// Generated by the protocol buffer compiler.  DO NOT EDIT!

#define INTERNAL_SUPPRESS_PROTOBUF_FIELD_DEPRECATION
#include "bcidata.pb.h"

#include <algorithm>

#include <google/protobuf/stubs/once.h>
#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/wire_format_lite_inl.h>
#include <google/protobuf/descriptor.h>
#include <google/protobuf/reflection_ops.h>
#include <google/protobuf/wire_format.h>
// @@protoc_insertion_point(includes)

namespace bci {

namespace {

const ::google::protobuf::Descriptor* Data_descriptor_ = NULL;
const ::google::protobuf::internal::GeneratedMessageReflection*
  Data_reflection_ = NULL;
const ::google::protobuf::Descriptor* Datum_descriptor_ = NULL;
const ::google::protobuf::internal::GeneratedMessageReflection*
  Datum_reflection_ = NULL;

}  // namespace


void protobuf_AssignDesc_bcidata_2eproto() {
  protobuf_AddDesc_bcidata_2eproto();
  const ::google::protobuf::FileDescriptor* file =
    ::google::protobuf::DescriptorPool::generated_pool()->FindFileByName(
      "bcidata.proto");
  GOOGLE_CHECK(file != NULL);
  Data_descriptor_ = file->message_type(0);
  static const int Data_offsets_[4] = {
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(Data, id_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(Data, type_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(Data, timestamp_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(Data, contents_),
  };
  Data_reflection_ =
    new ::google::protobuf::internal::GeneratedMessageReflection(
      Data_descriptor_,
      Data::default_instance_,
      Data_offsets_,
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(Data, _has_bits_[0]),
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(Data, _unknown_fields_),
      -1,
      ::google::protobuf::DescriptorPool::generated_pool(),
      ::google::protobuf::MessageFactory::generated_factory(),
      sizeof(Data));
  Datum_descriptor_ = file->message_type(1);
  static const int Datum_offsets_[3] = {
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(Datum, timestamp_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(Datum, thirdparty_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(Datum, sensors_),
  };
  Datum_reflection_ =
    new ::google::protobuf::internal::GeneratedMessageReflection(
      Datum_descriptor_,
      Datum::default_instance_,
      Datum_offsets_,
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(Datum, _has_bits_[0]),
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(Datum, _unknown_fields_),
      -1,
      ::google::protobuf::DescriptorPool::generated_pool(),
      ::google::protobuf::MessageFactory::generated_factory(),
      sizeof(Datum));
}

namespace {

GOOGLE_PROTOBUF_DECLARE_ONCE(protobuf_AssignDescriptors_once_);
inline void protobuf_AssignDescriptorsOnce() {
  ::google::protobuf::GoogleOnceInit(&protobuf_AssignDescriptors_once_,
                 &protobuf_AssignDesc_bcidata_2eproto);
}

void protobuf_RegisterTypes(const ::std::string&) {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedMessage(
    Data_descriptor_, &Data::default_instance());
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedMessage(
    Datum_descriptor_, &Datum::default_instance());
}

}  // namespace

void protobuf_ShutdownFile_bcidata_2eproto() {
  delete Data::default_instance_;
  delete Data_reflection_;
  delete Datum::default_instance_;
  delete Datum_reflection_;
}

void protobuf_AddDesc_bcidata_2eproto() {
  static bool already_here = false;
  if (already_here) return;
  already_here = true;
  GOOGLE_PROTOBUF_VERIFY_VERSION;

  ::google::protobuf::DescriptorPool::InternalAddGeneratedFile(
    "\n\rbcidata.proto\022\003bci\"Q\n\004Data\022\n\n\002id\030\001 \002(\003"
    "\022\014\n\004type\030\002 \002(\005\022\021\n\ttimestamp\030\003 \002(\003\022\034\n\010con"
    "tents\030\004 \003(\0132\n.bci.Datum\"\?\n\005Datum\022\021\n\ttime"
    "stamp\030\001 \002(\003\022\022\n\nthirdparty\030\002 \001(\005\022\017\n\007senso"
    "rs\030\003 \003(\002", 168);
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedFile(
    "bcidata.proto", &protobuf_RegisterTypes);
  Data::default_instance_ = new Data();
  Datum::default_instance_ = new Datum();
  Data::default_instance_->InitAsDefaultInstance();
  Datum::default_instance_->InitAsDefaultInstance();
  ::google::protobuf::internal::OnShutdown(&protobuf_ShutdownFile_bcidata_2eproto);
}

// Force AddDescriptors() to be called at static initialization time.
struct StaticDescriptorInitializer_bcidata_2eproto {
  StaticDescriptorInitializer_bcidata_2eproto() {
    protobuf_AddDesc_bcidata_2eproto();
  }
} static_descriptor_initializer_bcidata_2eproto_;


// ===================================================================

#ifndef _MSC_VER
const int Data::kIdFieldNumber;
const int Data::kTypeFieldNumber;
const int Data::kTimestampFieldNumber;
const int Data::kContentsFieldNumber;
#endif  // !_MSC_VER

Data::Data()
  : ::google::protobuf::Message() {
  SharedCtor();
}

void Data::InitAsDefaultInstance() {
}

Data::Data(const Data& from)
  : ::google::protobuf::Message() {
  SharedCtor();
  MergeFrom(from);
}

void Data::SharedCtor() {
  _cached_size_ = 0;
  id_ = GOOGLE_LONGLONG(0);
  type_ = 0;
  timestamp_ = GOOGLE_LONGLONG(0);
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
}

Data::~Data() {
  SharedDtor();
}

void Data::SharedDtor() {
  if (this != default_instance_) {
  }
}

void Data::SetCachedSize(int size) const {
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
}
const ::google::protobuf::Descriptor* Data::descriptor() {
  protobuf_AssignDescriptorsOnce();
  return Data_descriptor_;
}

const Data& Data::default_instance() {
  if (default_instance_ == NULL) protobuf_AddDesc_bcidata_2eproto();  return *default_instance_;
}

Data* Data::default_instance_ = NULL;

Data* Data::New() const {
  return new Data;
}

void Data::Clear() {
  if (_has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    id_ = GOOGLE_LONGLONG(0);
    type_ = 0;
    timestamp_ = GOOGLE_LONGLONG(0);
  }
  contents_.Clear();
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
  mutable_unknown_fields()->Clear();
}

bool Data::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!(EXPRESSION)) return false
  ::google::protobuf::uint32 tag;
  while ((tag = input->ReadTag()) != 0) {
    switch (::google::protobuf::internal::WireFormatLite::GetTagFieldNumber(tag)) {
      // required int64 id = 1;
      case 1: {
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_VARINT) {
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::int64, ::google::protobuf::internal::WireFormatLite::TYPE_INT64>(
                 input, &id_)));
          set_has_id();
        } else {
          goto handle_uninterpreted;
        }
        if (input->ExpectTag(16)) goto parse_type;
        break;
      }
      
      // required int32 type = 2;
      case 2: {
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_VARINT) {
         parse_type:
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::int32, ::google::protobuf::internal::WireFormatLite::TYPE_INT32>(
                 input, &type_)));
          set_has_type();
        } else {
          goto handle_uninterpreted;
        }
        if (input->ExpectTag(24)) goto parse_timestamp;
        break;
      }
      
      // required int64 timestamp = 3;
      case 3: {
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_VARINT) {
         parse_timestamp:
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::int64, ::google::protobuf::internal::WireFormatLite::TYPE_INT64>(
                 input, &timestamp_)));
          set_has_timestamp();
        } else {
          goto handle_uninterpreted;
        }
        if (input->ExpectTag(34)) goto parse_contents;
        break;
      }
      
      // repeated .bci.Datum contents = 4;
      case 4: {
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_LENGTH_DELIMITED) {
         parse_contents:
          DO_(::google::protobuf::internal::WireFormatLite::ReadMessageNoVirtual(
                input, add_contents()));
        } else {
          goto handle_uninterpreted;
        }
        if (input->ExpectTag(34)) goto parse_contents;
        if (input->ExpectAtEnd()) return true;
        break;
      }
      
      default: {
      handle_uninterpreted:
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_END_GROUP) {
          return true;
        }
        DO_(::google::protobuf::internal::WireFormat::SkipField(
              input, tag, mutable_unknown_fields()));
        break;
      }
    }
  }
  return true;
#undef DO_
}

void Data::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // required int64 id = 1;
  if (has_id()) {
    ::google::protobuf::internal::WireFormatLite::WriteInt64(1, this->id(), output);
  }
  
  // required int32 type = 2;
  if (has_type()) {
    ::google::protobuf::internal::WireFormatLite::WriteInt32(2, this->type(), output);
  }
  
  // required int64 timestamp = 3;
  if (has_timestamp()) {
    ::google::protobuf::internal::WireFormatLite::WriteInt64(3, this->timestamp(), output);
  }
  
  // repeated .bci.Datum contents = 4;
  for (int i = 0; i < this->contents_size(); i++) {
    ::google::protobuf::internal::WireFormatLite::WriteMessageMaybeToArray(
      4, this->contents(i), output);
  }
  
  if (!unknown_fields().empty()) {
    ::google::protobuf::internal::WireFormat::SerializeUnknownFields(
        unknown_fields(), output);
  }
}

::google::protobuf::uint8* Data::SerializeWithCachedSizesToArray(
    ::google::protobuf::uint8* target) const {
  // required int64 id = 1;
  if (has_id()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteInt64ToArray(1, this->id(), target);
  }
  
  // required int32 type = 2;
  if (has_type()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteInt32ToArray(2, this->type(), target);
  }
  
  // required int64 timestamp = 3;
  if (has_timestamp()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteInt64ToArray(3, this->timestamp(), target);
  }
  
  // repeated .bci.Datum contents = 4;
  for (int i = 0; i < this->contents_size(); i++) {
    target = ::google::protobuf::internal::WireFormatLite::
      WriteMessageNoVirtualToArray(
        4, this->contents(i), target);
  }
  
  if (!unknown_fields().empty()) {
    target = ::google::protobuf::internal::WireFormat::SerializeUnknownFieldsToArray(
        unknown_fields(), target);
  }
  return target;
}

int Data::ByteSize() const {
  int total_size = 0;
  
  if (_has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    // required int64 id = 1;
    if (has_id()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::Int64Size(
          this->id());
    }
    
    // required int32 type = 2;
    if (has_type()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::Int32Size(
          this->type());
    }
    
    // required int64 timestamp = 3;
    if (has_timestamp()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::Int64Size(
          this->timestamp());
    }
    
  }
  // repeated .bci.Datum contents = 4;
  total_size += 1 * this->contents_size();
  for (int i = 0; i < this->contents_size(); i++) {
    total_size +=
      ::google::protobuf::internal::WireFormatLite::MessageSizeNoVirtual(
        this->contents(i));
  }
  
  if (!unknown_fields().empty()) {
    total_size +=
      ::google::protobuf::internal::WireFormat::ComputeUnknownFieldsSize(
        unknown_fields());
  }
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = total_size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
  return total_size;
}

void Data::MergeFrom(const ::google::protobuf::Message& from) {
  GOOGLE_CHECK_NE(&from, this);
  const Data* source =
    ::google::protobuf::internal::dynamic_cast_if_available<const Data*>(
      &from);
  if (source == NULL) {
    ::google::protobuf::internal::ReflectionOps::Merge(from, this);
  } else {
    MergeFrom(*source);
  }
}

void Data::MergeFrom(const Data& from) {
  GOOGLE_CHECK_NE(&from, this);
  contents_.MergeFrom(from.contents_);
  if (from._has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    if (from.has_id()) {
      set_id(from.id());
    }
    if (from.has_type()) {
      set_type(from.type());
    }
    if (from.has_timestamp()) {
      set_timestamp(from.timestamp());
    }
  }
  mutable_unknown_fields()->MergeFrom(from.unknown_fields());
}

void Data::CopyFrom(const ::google::protobuf::Message& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void Data::CopyFrom(const Data& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool Data::IsInitialized() const {
  if ((_has_bits_[0] & 0x00000007) != 0x00000007) return false;
  
  for (int i = 0; i < contents_size(); i++) {
    if (!this->contents(i).IsInitialized()) return false;
  }
  return true;
}

void Data::Swap(Data* other) {
  if (other != this) {
    std::swap(id_, other->id_);
    std::swap(type_, other->type_);
    std::swap(timestamp_, other->timestamp_);
    contents_.Swap(&other->contents_);
    std::swap(_has_bits_[0], other->_has_bits_[0]);
    _unknown_fields_.Swap(&other->_unknown_fields_);
    std::swap(_cached_size_, other->_cached_size_);
  }
}

::google::protobuf::Metadata Data::GetMetadata() const {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::Metadata metadata;
  metadata.descriptor = Data_descriptor_;
  metadata.reflection = Data_reflection_;
  return metadata;
}


// ===================================================================

#ifndef _MSC_VER
const int Datum::kTimestampFieldNumber;
const int Datum::kThirdpartyFieldNumber;
const int Datum::kSensorsFieldNumber;
#endif  // !_MSC_VER

Datum::Datum()
  : ::google::protobuf::Message() {
  SharedCtor();
}

void Datum::InitAsDefaultInstance() {
}

Datum::Datum(const Datum& from)
  : ::google::protobuf::Message() {
  SharedCtor();
  MergeFrom(from);
}

void Datum::SharedCtor() {
  _cached_size_ = 0;
  timestamp_ = GOOGLE_LONGLONG(0);
  thirdparty_ = 0;
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
}

Datum::~Datum() {
  SharedDtor();
}

void Datum::SharedDtor() {
  if (this != default_instance_) {
  }
}

void Datum::SetCachedSize(int size) const {
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
}
const ::google::protobuf::Descriptor* Datum::descriptor() {
  protobuf_AssignDescriptorsOnce();
  return Datum_descriptor_;
}

const Datum& Datum::default_instance() {
  if (default_instance_ == NULL) protobuf_AddDesc_bcidata_2eproto();  return *default_instance_;
}

Datum* Datum::default_instance_ = NULL;

Datum* Datum::New() const {
  return new Datum;
}

void Datum::Clear() {
  if (_has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    timestamp_ = GOOGLE_LONGLONG(0);
    thirdparty_ = 0;
  }
  sensors_.Clear();
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
  mutable_unknown_fields()->Clear();
}

bool Datum::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!(EXPRESSION)) return false
  ::google::protobuf::uint32 tag;
  while ((tag = input->ReadTag()) != 0) {
    switch (::google::protobuf::internal::WireFormatLite::GetTagFieldNumber(tag)) {
      // required int64 timestamp = 1;
      case 1: {
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_VARINT) {
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::int64, ::google::protobuf::internal::WireFormatLite::TYPE_INT64>(
                 input, &timestamp_)));
          set_has_timestamp();
        } else {
          goto handle_uninterpreted;
        }
        if (input->ExpectTag(16)) goto parse_thirdparty;
        break;
      }
      
      // optional int32 thirdparty = 2;
      case 2: {
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_VARINT) {
         parse_thirdparty:
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::int32, ::google::protobuf::internal::WireFormatLite::TYPE_INT32>(
                 input, &thirdparty_)));
          set_has_thirdparty();
        } else {
          goto handle_uninterpreted;
        }
        if (input->ExpectTag(29)) goto parse_sensors;
        break;
      }
      
      // repeated float sensors = 3;
      case 3: {
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_FIXED32) {
         parse_sensors:
          DO_((::google::protobuf::internal::WireFormatLite::ReadRepeatedPrimitive<
                   float, ::google::protobuf::internal::WireFormatLite::TYPE_FLOAT>(
                 1, 29, input, this->mutable_sensors())));
        } else if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag)
                   == ::google::protobuf::internal::WireFormatLite::
                      WIRETYPE_LENGTH_DELIMITED) {
          DO_((::google::protobuf::internal::WireFormatLite::ReadPackedPrimitiveNoInline<
                   float, ::google::protobuf::internal::WireFormatLite::TYPE_FLOAT>(
                 input, this->mutable_sensors())));
        } else {
          goto handle_uninterpreted;
        }
        if (input->ExpectTag(29)) goto parse_sensors;
        if (input->ExpectAtEnd()) return true;
        break;
      }
      
      default: {
      handle_uninterpreted:
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_END_GROUP) {
          return true;
        }
        DO_(::google::protobuf::internal::WireFormat::SkipField(
              input, tag, mutable_unknown_fields()));
        break;
      }
    }
  }
  return true;
#undef DO_
}

void Datum::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // required int64 timestamp = 1;
  if (has_timestamp()) {
    ::google::protobuf::internal::WireFormatLite::WriteInt64(1, this->timestamp(), output);
  }
  
  // optional int32 thirdparty = 2;
  if (has_thirdparty()) {
    ::google::protobuf::internal::WireFormatLite::WriteInt32(2, this->thirdparty(), output);
  }
  
  // repeated float sensors = 3;
  for (int i = 0; i < this->sensors_size(); i++) {
    ::google::protobuf::internal::WireFormatLite::WriteFloat(
      3, this->sensors(i), output);
  }
  
  if (!unknown_fields().empty()) {
    ::google::protobuf::internal::WireFormat::SerializeUnknownFields(
        unknown_fields(), output);
  }
}

::google::protobuf::uint8* Datum::SerializeWithCachedSizesToArray(
    ::google::protobuf::uint8* target) const {
  // required int64 timestamp = 1;
  if (has_timestamp()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteInt64ToArray(1, this->timestamp(), target);
  }
  
  // optional int32 thirdparty = 2;
  if (has_thirdparty()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteInt32ToArray(2, this->thirdparty(), target);
  }
  
  // repeated float sensors = 3;
  for (int i = 0; i < this->sensors_size(); i++) {
    target = ::google::protobuf::internal::WireFormatLite::
      WriteFloatToArray(3, this->sensors(i), target);
  }
  
  if (!unknown_fields().empty()) {
    target = ::google::protobuf::internal::WireFormat::SerializeUnknownFieldsToArray(
        unknown_fields(), target);
  }
  return target;
}

int Datum::ByteSize() const {
  int total_size = 0;
  
  if (_has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    // required int64 timestamp = 1;
    if (has_timestamp()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::Int64Size(
          this->timestamp());
    }
    
    // optional int32 thirdparty = 2;
    if (has_thirdparty()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::Int32Size(
          this->thirdparty());
    }
    
  }
  // repeated float sensors = 3;
  {
    int data_size = 0;
    data_size = 4 * this->sensors_size();
    total_size += 1 * this->sensors_size() + data_size;
  }
  
  if (!unknown_fields().empty()) {
    total_size +=
      ::google::protobuf::internal::WireFormat::ComputeUnknownFieldsSize(
        unknown_fields());
  }
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = total_size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
  return total_size;
}

void Datum::MergeFrom(const ::google::protobuf::Message& from) {
  GOOGLE_CHECK_NE(&from, this);
  const Datum* source =
    ::google::protobuf::internal::dynamic_cast_if_available<const Datum*>(
      &from);
  if (source == NULL) {
    ::google::protobuf::internal::ReflectionOps::Merge(from, this);
  } else {
    MergeFrom(*source);
  }
}

void Datum::MergeFrom(const Datum& from) {
  GOOGLE_CHECK_NE(&from, this);
  sensors_.MergeFrom(from.sensors_);
  if (from._has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    if (from.has_timestamp()) {
      set_timestamp(from.timestamp());
    }
    if (from.has_thirdparty()) {
      set_thirdparty(from.thirdparty());
    }
  }
  mutable_unknown_fields()->MergeFrom(from.unknown_fields());
}

void Datum::CopyFrom(const ::google::protobuf::Message& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void Datum::CopyFrom(const Datum& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool Datum::IsInitialized() const {
  if ((_has_bits_[0] & 0x00000001) != 0x00000001) return false;
  
  return true;
}

void Datum::Swap(Datum* other) {
  if (other != this) {
    std::swap(timestamp_, other->timestamp_);
    std::swap(thirdparty_, other->thirdparty_);
    sensors_.Swap(&other->sensors_);
    std::swap(_has_bits_[0], other->_has_bits_[0]);
    _unknown_fields_.Swap(&other->_unknown_fields_);
    std::swap(_cached_size_, other->_cached_size_);
  }
}

::google::protobuf::Metadata Datum::GetMetadata() const {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::Metadata metadata;
  metadata.descriptor = Datum_descriptor_;
  metadata.reflection = Datum_reflection_;
  return metadata;
}


// @@protoc_insertion_point(namespace_scope)

}  // namespace bci

// @@protoc_insertion_point(global_scope)