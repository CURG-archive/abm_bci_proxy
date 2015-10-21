#ifndef DATA_BLOCK_H_
#define DATA_BLOCK_H_

#include <vector>

class DataBlock {
public:
	unsigned char thirdparty;
	std::vector<float> data;
	unsigned long timestamp;
};

#endif