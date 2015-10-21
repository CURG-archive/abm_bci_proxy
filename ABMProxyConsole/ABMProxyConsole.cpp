// ABMProxyConsole.cpp
// This application serves as a simple ABM B-Alert X-10 to ZMQ proxy server.
// It uses Google Protobufs (v2.4.1) to efficiently transfer the BCI data over the wire.
// Author: Robert Ying (robert.ying@columbia.edu)
//

#include "stdafx.h"
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <deque>
#include <process.h>
#include <concrt.h>

// Due to painful reasons, zmq.hpp must be included before windows.h
#include "zmq.hpp"

// Due to even more painful reasons, AbmSdkInclude.h must be included after windows.h
#include <Windows.h>
#include "AbmSdkInclude.h"
#include "bcidata.pb.h"

#include "DataBlock.h"

concurrency::critical_section bci_mutex;
concurrency::critical_section queue_mutex;

HANDLE streaming_thread_handle = NULL;
HANDLE reading_thread_handle = NULL;

int num_channels = 0;
std::vector<DataBlock> data_queue;						// grouped data by channel and timestamp and event

BOOL running = true;

BOOL OnExit() {
	std::cout << "Exiting from ABMProxy" << std::endl;
	running = false;

	std::cout << "Waiting for worker thread to die" << std::endl;
	if (streaming_thread_handle) {
		WaitForSingleObject(streaming_thread_handle, INFINITE);
	}
	if (reading_thread_handle) {
		WaitForSingleObject(reading_thread_handle, INFINITE);
	}

	std::cout << "Stopping acquisition" << std::endl;

	{
		concurrency::critical_section::scoped_lock lock(bci_mutex);
		StopAcquisition();
	}
	
	ExitProcess(0);
	return true;
}

unsigned int ConvertTimestamp(unsigned char const * ts) {
	unsigned int converted_timestamp;
	unsigned char * temp = reinterpret_cast<unsigned char *>(&converted_timestamp);
	temp[3] = ts[0];
	temp[2] = ts[1];
	temp[1] = ts[2];
	temp[0] = ts[3];
	return converted_timestamp;
}

DWORD WINAPI reading_thread(void *param) {
	static const int ABM_SAMPLELENGTH = 4;					// approximate duration of one sample in ms
	static const int ABM_TP_PACKAGESIZE = 12;				// number of bytes in one package of thirdparty data
	static const int ABM_TP_TIME_OFFSET = 3;				// offset (in bytes) of where the third party timestamp starts
	static const int ABM_TP_DATA_OFFSET = 10;				// offset (in bytes) of where the third party data starts
	static const int ABM_TIME_PACKAGESIZE = 4;				// number of bytes in one timestamp package
	static const int ABM_RAW_PACKAGESIZE = 16;				// number of bytes in one raw data package
	static const int ABM_RAW_CHANNEL1_OFFSET = 6;			// offset (in bytes) until channel 1 starts

	std::deque<float> raw_data;								// raw data as received
	std::deque<unsigned int> raw_data_ts;					// timestamps for the raw data (ms)
	std::deque<unsigned char> events;						// events as received
	std::deque<unsigned int> events_ts;						// timestamps for the events (ms)
	unsigned char latest_event = 0;							//

	while (running) {
		{
			concurrency::critical_section::scoped_lock lock(bci_mutex);
			int rawCount, thirdPartySize;
			unsigned char * thirdParty = GetThirdPartyData(thirdPartySize);

			float * raw = GetRawData(rawCount);
			unsigned char * timeStamps = GetTimeStampsStreamData(TIMESTAMP_RAW);

			if (raw) {
				for (int i = 0; i < rawCount; ++i) {
					int offset = ABM_RAW_PACKAGESIZE * i + ABM_RAW_CHANNEL1_OFFSET;

					raw_data.insert(raw_data.end(), raw + offset, raw + offset + num_channels);
					offset = ABM_TIME_PACKAGESIZE * i;
					int new_ts = ConvertTimestamp(timeStamps + offset);

					if (i % 2 == 0) {
						// sensor packets come in pairs; we artificially move the timestamp of
						// the earlier part of each pair back one sample period for consistency
						new_ts -= ABM_SAMPLELENGTH;
					}
					raw_data_ts.push_back(new_ts);
				}
			}

			if (thirdParty) {
				int numEvents = thirdPartySize / ABM_TP_PACKAGESIZE;
				for (int i = 0; i < numEvents; ++i) {
					int offset = i * ABM_TP_PACKAGESIZE;
					events_ts.push_back(ConvertTimestamp(thirdParty + offset + ABM_TP_TIME_OFFSET));
					events.push_back(thirdParty[offset + ABM_TP_DATA_OFFSET]);
				}
			}
		}

		{
			concurrency::critical_section::scoped_lock lock(queue_mutex);

			while (!raw_data_ts.empty()) {
				while (events_ts.size() && events_ts.front() <= raw_data_ts.front()) {
					latest_event = events.front();

					events.pop_front();
					events_ts.pop_front();
				}

				DataBlock db;
				db.timestamp = raw_data_ts.front();
				db.thirdparty = latest_event;

				for (int i = 0; i < num_channels; ++i) {
					db.data.push_back(raw_data.front());
					raw_data.pop_front();
				}

				data_queue.push_back(db);
				raw_data_ts.pop_front();
			}
		}
		assert(raw_data.empty());

		Sleep(10); // called 100 times per second
		if (!running) {
			return 0;
		}
	}
	return 0;
}

DWORD WINAPI streaming_thread(void *param) {
	int port = *reinterpret_cast<int*>(param);
	

	zmq::context_t context(1);
	zmq::socket_t socket(context, ZMQ_PUB);

	std::stringstream sstm;
	sstm << "tcp://*:" << port;

	std::string url = sstm.str();
	std::cout << "Started streaming thread on " << url << std::endl;
	socket.bind(url);

	long seq = 0;

	
	while (running) {
		bci::Data data;
		bool data_to_send = false;
		{
			concurrency::critical_section::scoped_lock lock(queue_mutex);
			if (data_queue.size()) {
				data_to_send = true;

				// load data
				DataBlock first = data_queue[0];

				data.set_timestamp(first.timestamp);
				data.set_id(seq);
				data.set_type(0);

				for (std::vector<DataBlock>::iterator it = data_queue.begin(); it != data_queue.end(); ++it) {
					bci::Datum * datum = data.add_contents();
					datum->set_thirdparty(it->thirdparty);
					datum->set_timestamp(it->timestamp);
					for (std::vector<float>::iterator it2 = it->data.begin(); it2 != it->data.end(); ++it2) {
						datum->add_sensors(*it2);
					}
				}
				data_queue.clear();
			}
		}

		if (data_to_send) {
			std::string serialized_data;
			data.SerializeToString(&serialized_data);

			zmq::message_t msg(serialized_data.size());
			memcpy(reinterpret_cast<void*>(msg.data()), serialized_data.c_str(), serialized_data.size());

			socket.send(msg);

			seq++;
		}
		Sleep(20); // 50 times per second
		if (!running) {
			break;
		}
	}

	return 0;
}

void InitBCI() {
	concurrency::critical_section::scoped_lock lock(bci_mutex);

	std::cout << "Initializing BCI" << std::endl;

	if (StopAcquisition() != ID_WRONG_SEQUENCY_OF_COMMAND) {
		std::cerr << "Stopped previous data acquisition" << std::endl;
	}

	_DEVICE_INFO *devInfo;
	if (!(devInfo = GetDeviceInfo())) {
		throw("GetDeviceInfo() failed");
	}

	std::cout << "ABM Device Info:" << std::endl;
	std::cout << "Device name: " << devInfo->chDeviceName << std::endl;
	std::cout << "COM Port: " << devInfo->nCommPort << std::endl;
	std::cout << "ECG Channel: " << devInfo->nECGPos << std::endl;
	std::cout << "Number of channels: " << devInfo->nNumberOfChannel << std::endl;

	num_channels = devInfo->nNumberOfChannel;

	if (num_channels < 0) {
		std::cerr << "ABM X10 not connected" << std::endl;
		ExitProcess(1);
	}

	std::stringstream destfilepath;
	SYSTEMTIME stime;
	GetLocalTime(&stime);

	int err;


	destfilepath << "data\\" << stime.wYear << "_" << stime.wMonth << "_" << stime.wDay << "_" << stime.wHour << "_" << stime.wMinute << "_" << stime.wSecond << ".ebs";
	std::string dfp = destfilepath.str();

	char fullpath[4096] = "";
	char *pszfn = NULL;

	err = GetFullPathNameA(dfp.c_str(), sizeof(fullpath), fullpath, &pszfn);

	std::cout << "Setting destination file path to " << fullpath << std::endl;

	if (!(err = SetDestinationFile(fullpath))) {
		std::cerr << "SetDestinationFile failed! err " << err << std::endl;
		ExitProcess(1);
	}

	std::cout << "Initiating session..." << std::endl;
	if ((err = InitSession(ABM_DEVICE_X10Standard, ABM_SESSION_RAW, -1, FALSE)) != INIT_SESSION_OK) {
		std::cerr << "InitSession failed! err " << err << std::endl;
		switch (err) {
		case ID_WRONG_SEQUENCY_OF_COMMAND:
			std::cerr << "Wrong command sequence" << std::endl;
			break;
		case INIT_SESSION_NO:
			std::cerr << "Session initiation failed" << std::endl;
			break;
		case INIT_SESSION_NO_DESTFILE_FAILED:
			std::cerr << "No destination file!" << std::endl;
			break;
		}
		ExitProcess(1);
	}

	std::cout << "Getting channel map info" << std::endl;
	_CHANNELMAP_INFO channelMap;
	if (!GetChannelMapInfo(channelMap)) {
		std::cerr << "GetChannelMapInfo failed!" << std::endl;
		ExitProcess(1);
	}

	if (channelMap.nDeviceTypeCode != 0) {
		std::cerr << "ABM X10 not found! :(" << std::endl;
		ExitProcess(1);
	}

	_EEGCHANNELS_INFO& eegChannels = channelMap.stEEGChannels;
	for (int i = 0; i < channelMap.nSize; ++i) {
		std::cout << eegChannels.cChName[i] << " " << eegChannels.bChUsed[i] << " " << eegChannels.bChUsedInQualityData[i] << std::endl;
	}

	std::cout << "Starting acquisition..." << std::endl;
	if (StartAcquisition() != ACQ_STARTED_OK) {
		std::cerr << "StartAcquisition failed!" << std::endl;
		ExitProcess(1);
	}
	
	running = true;

	std::cout << "BCI initialization done!" << std::endl;

}


int _tmain(int argc, _TCHAR* argv[])
{
	if (!SetConsoleCtrlHandler((PHANDLER_ROUTINE) OnExit, TRUE)) {
		std::cerr << "Failed to install console exit handler" << std::endl;
		ExitProcess(1);
	}
	
	InitBCI();
	
	int sport = 5555;
	streaming_thread_handle = CreateThread(NULL, 0, streaming_thread, &sport, 0, NULL);
	reading_thread_handle = CreateThread(NULL, 0, reading_thread, NULL, 0, NULL);

	std::cout << "^C to quit" << std::endl;
	while (running) {
		Sleep(100);
	}
	return 0;
}

