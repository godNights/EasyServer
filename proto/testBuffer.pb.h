// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: testBuffer.proto

#ifndef PROTOBUF_INCLUDED_testBuffer_2eproto
#define PROTOBUF_INCLUDED_testBuffer_2eproto

#include <limits>
#include <string>

#include <google/protobuf/port_def.inc>
#if PROTOBUF_VERSION < 3007000
#error This file was generated by a newer version of protoc which is
#error incompatible with your Protocol Buffer headers. Please update
#error your headers.
#endif
#if 3007001 < PROTOBUF_MIN_PROTOC_VERSION
#error This file was generated by an older version of protoc which is
#error incompatible with your Protocol Buffer headers. Please
#error regenerate this file with a newer version of protoc.
#endif

#include <google/protobuf/port_undef.inc>
#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/arena.h>
#include <google/protobuf/arenastring.h>
#include <google/protobuf/generated_message_table_driven.h>
#include <google/protobuf/generated_message_util.h>
#include <google/protobuf/inlined_string_field.h>
#include <google/protobuf/metadata.h>
#include <google/protobuf/message.h>
#include <google/protobuf/repeated_field.h>  // IWYU pragma: export
#include <google/protobuf/extension_set.h>  // IWYU pragma: export
#include <google/protobuf/unknown_field_set.h>
// @@protoc_insertion_point(includes)
#include <google/protobuf/port_def.inc>
#define PROTOBUF_INTERNAL_EXPORT_testBuffer_2eproto

// Internal implementation detail -- do not use these members.
struct TableStruct_testBuffer_2eproto {
  static const ::google::protobuf::internal::ParseTableField entries[]
    PROTOBUF_SECTION_VARIABLE(protodesc_cold);
  static const ::google::protobuf::internal::AuxillaryParseTableField aux[]
    PROTOBUF_SECTION_VARIABLE(protodesc_cold);
  static const ::google::protobuf::internal::ParseTable schema[2]
    PROTOBUF_SECTION_VARIABLE(protodesc_cold);
  static const ::google::protobuf::internal::FieldMetadata field_metadata[];
  static const ::google::protobuf::internal::SerializationTable serialization_table[];
  static const ::google::protobuf::uint32 offsets[];
};
void AddDescriptors_testBuffer_2eproto();
class ClientBuffer;
class ClientBufferDefaultTypeInternal;
extern ClientBufferDefaultTypeInternal _ClientBuffer_default_instance_;
class ServerBuffer;
class ServerBufferDefaultTypeInternal;
extern ServerBufferDefaultTypeInternal _ServerBuffer_default_instance_;
namespace google {
namespace protobuf {
template<> ::ClientBuffer* Arena::CreateMaybeMessage<::ClientBuffer>(Arena*);
template<> ::ServerBuffer* Arena::CreateMaybeMessage<::ServerBuffer>(Arena*);
}  // namespace protobuf
}  // namespace google

// ===================================================================

class ClientBuffer :
    public ::google::protobuf::Message /* @@protoc_insertion_point(class_definition:ClientBuffer) */ {
 public:
  ClientBuffer();
  virtual ~ClientBuffer();

  ClientBuffer(const ClientBuffer& from);

  inline ClientBuffer& operator=(const ClientBuffer& from) {
    CopyFrom(from);
    return *this;
  }
  #if LANG_CXX11
  ClientBuffer(ClientBuffer&& from) noexcept
    : ClientBuffer() {
    *this = ::std::move(from);
  }

  inline ClientBuffer& operator=(ClientBuffer&& from) noexcept {
    if (GetArenaNoVirtual() == from.GetArenaNoVirtual()) {
      if (this != &from) InternalSwap(&from);
    } else {
      CopyFrom(from);
    }
    return *this;
  }
  #endif
  static const ::google::protobuf::Descriptor* descriptor() {
    return default_instance().GetDescriptor();
  }
  static const ClientBuffer& default_instance();

  static void InitAsDefaultInstance();  // FOR INTERNAL USE ONLY
  static inline const ClientBuffer* internal_default_instance() {
    return reinterpret_cast<const ClientBuffer*>(
               &_ClientBuffer_default_instance_);
  }
  static constexpr int kIndexInFileMessages =
    0;

  void Swap(ClientBuffer* other);
  friend void swap(ClientBuffer& a, ClientBuffer& b) {
    a.Swap(&b);
  }

  // implements Message ----------------------------------------------

  inline ClientBuffer* New() const final {
    return CreateMaybeMessage<ClientBuffer>(nullptr);
  }

  ClientBuffer* New(::google::protobuf::Arena* arena) const final {
    return CreateMaybeMessage<ClientBuffer>(arena);
  }
  void CopyFrom(const ::google::protobuf::Message& from) final;
  void MergeFrom(const ::google::protobuf::Message& from) final;
  void CopyFrom(const ClientBuffer& from);
  void MergeFrom(const ClientBuffer& from);
  PROTOBUF_ATTRIBUTE_REINITIALIZES void Clear() final;
  bool IsInitialized() const final;

  size_t ByteSizeLong() const final;
  #if GOOGLE_PROTOBUF_ENABLE_EXPERIMENTAL_PARSER
  static const char* _InternalParse(const char* begin, const char* end, void* object, ::google::protobuf::internal::ParseContext* ctx);
  ::google::protobuf::internal::ParseFunc _ParseFunc() const final { return _InternalParse; }
  #else
  bool MergePartialFromCodedStream(
      ::google::protobuf::io::CodedInputStream* input) final;
  #endif  // GOOGLE_PROTOBUF_ENABLE_EXPERIMENTAL_PARSER
  void SerializeWithCachedSizes(
      ::google::protobuf::io::CodedOutputStream* output) const final;
  ::google::protobuf::uint8* InternalSerializeWithCachedSizesToArray(
      ::google::protobuf::uint8* target) const final;
  int GetCachedSize() const final { return _cached_size_.Get(); }

  private:
  void SharedCtor();
  void SharedDtor();
  void SetCachedSize(int size) const final;
  void InternalSwap(ClientBuffer* other);
  private:
  inline ::google::protobuf::Arena* GetArenaNoVirtual() const {
    return nullptr;
  }
  inline void* MaybeArenaPtr() const {
    return nullptr;
  }
  public:

  ::google::protobuf::Metadata GetMetadata() const final;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  // string text = 3;
  void clear_text();
  static const int kTextFieldNumber = 3;
  const ::std::string& text() const;
  void set_text(const ::std::string& value);
  #if LANG_CXX11
  void set_text(::std::string&& value);
  #endif
  void set_text(const char* value);
  void set_text(const char* value, size_t size);
  ::std::string* mutable_text();
  ::std::string* release_text();
  void set_allocated_text(::std::string* text);

  // uint32 sockFd = 1;
  void clear_sockfd();
  static const int kSockFdFieldNumber = 1;
  ::google::protobuf::uint32 sockfd() const;
  void set_sockfd(::google::protobuf::uint32 value);

  // uint32 sequence = 2;
  void clear_sequence();
  static const int kSequenceFieldNumber = 2;
  ::google::protobuf::uint32 sequence() const;
  void set_sequence(::google::protobuf::uint32 value);

  // @@protoc_insertion_point(class_scope:ClientBuffer)
 private:
  class HasBitSetters;

  ::google::protobuf::internal::InternalMetadataWithArena _internal_metadata_;
  ::google::protobuf::internal::ArenaStringPtr text_;
  ::google::protobuf::uint32 sockfd_;
  ::google::protobuf::uint32 sequence_;
  mutable ::google::protobuf::internal::CachedSize _cached_size_;
  friend struct ::TableStruct_testBuffer_2eproto;
};
// -------------------------------------------------------------------

class ServerBuffer :
    public ::google::protobuf::Message /* @@protoc_insertion_point(class_definition:ServerBuffer) */ {
 public:
  ServerBuffer();
  virtual ~ServerBuffer();

  ServerBuffer(const ServerBuffer& from);

  inline ServerBuffer& operator=(const ServerBuffer& from) {
    CopyFrom(from);
    return *this;
  }
  #if LANG_CXX11
  ServerBuffer(ServerBuffer&& from) noexcept
    : ServerBuffer() {
    *this = ::std::move(from);
  }

  inline ServerBuffer& operator=(ServerBuffer&& from) noexcept {
    if (GetArenaNoVirtual() == from.GetArenaNoVirtual()) {
      if (this != &from) InternalSwap(&from);
    } else {
      CopyFrom(from);
    }
    return *this;
  }
  #endif
  static const ::google::protobuf::Descriptor* descriptor() {
    return default_instance().GetDescriptor();
  }
  static const ServerBuffer& default_instance();

  static void InitAsDefaultInstance();  // FOR INTERNAL USE ONLY
  static inline const ServerBuffer* internal_default_instance() {
    return reinterpret_cast<const ServerBuffer*>(
               &_ServerBuffer_default_instance_);
  }
  static constexpr int kIndexInFileMessages =
    1;

  void Swap(ServerBuffer* other);
  friend void swap(ServerBuffer& a, ServerBuffer& b) {
    a.Swap(&b);
  }

  // implements Message ----------------------------------------------

  inline ServerBuffer* New() const final {
    return CreateMaybeMessage<ServerBuffer>(nullptr);
  }

  ServerBuffer* New(::google::protobuf::Arena* arena) const final {
    return CreateMaybeMessage<ServerBuffer>(arena);
  }
  void CopyFrom(const ::google::protobuf::Message& from) final;
  void MergeFrom(const ::google::protobuf::Message& from) final;
  void CopyFrom(const ServerBuffer& from);
  void MergeFrom(const ServerBuffer& from);
  PROTOBUF_ATTRIBUTE_REINITIALIZES void Clear() final;
  bool IsInitialized() const final;

  size_t ByteSizeLong() const final;
  #if GOOGLE_PROTOBUF_ENABLE_EXPERIMENTAL_PARSER
  static const char* _InternalParse(const char* begin, const char* end, void* object, ::google::protobuf::internal::ParseContext* ctx);
  ::google::protobuf::internal::ParseFunc _ParseFunc() const final { return _InternalParse; }
  #else
  bool MergePartialFromCodedStream(
      ::google::protobuf::io::CodedInputStream* input) final;
  #endif  // GOOGLE_PROTOBUF_ENABLE_EXPERIMENTAL_PARSER
  void SerializeWithCachedSizes(
      ::google::protobuf::io::CodedOutputStream* output) const final;
  ::google::protobuf::uint8* InternalSerializeWithCachedSizesToArray(
      ::google::protobuf::uint8* target) const final;
  int GetCachedSize() const final { return _cached_size_.Get(); }

  private:
  void SharedCtor();
  void SharedDtor();
  void SetCachedSize(int size) const final;
  void InternalSwap(ServerBuffer* other);
  private:
  inline ::google::protobuf::Arena* GetArenaNoVirtual() const {
    return nullptr;
  }
  inline void* MaybeArenaPtr() const {
    return nullptr;
  }
  public:

  ::google::protobuf::Metadata GetMetadata() const final;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  // uint32 sequence = 1;
  void clear_sequence();
  static const int kSequenceFieldNumber = 1;
  ::google::protobuf::uint32 sequence() const;
  void set_sequence(::google::protobuf::uint32 value);

  // @@protoc_insertion_point(class_scope:ServerBuffer)
 private:
  class HasBitSetters;

  ::google::protobuf::internal::InternalMetadataWithArena _internal_metadata_;
  ::google::protobuf::uint32 sequence_;
  mutable ::google::protobuf::internal::CachedSize _cached_size_;
  friend struct ::TableStruct_testBuffer_2eproto;
};
// ===================================================================


// ===================================================================

#ifdef __GNUC__
  #pragma GCC diagnostic push
  #pragma GCC diagnostic ignored "-Wstrict-aliasing"
#endif  // __GNUC__
// ClientBuffer

// uint32 sockFd = 1;
inline void ClientBuffer::clear_sockfd() {
  sockfd_ = 0u;
}
inline ::google::protobuf::uint32 ClientBuffer::sockfd() const {
  // @@protoc_insertion_point(field_get:ClientBuffer.sockFd)
  return sockfd_;
}
inline void ClientBuffer::set_sockfd(::google::protobuf::uint32 value) {
  
  sockfd_ = value;
  // @@protoc_insertion_point(field_set:ClientBuffer.sockFd)
}

// uint32 sequence = 2;
inline void ClientBuffer::clear_sequence() {
  sequence_ = 0u;
}
inline ::google::protobuf::uint32 ClientBuffer::sequence() const {
  // @@protoc_insertion_point(field_get:ClientBuffer.sequence)
  return sequence_;
}
inline void ClientBuffer::set_sequence(::google::protobuf::uint32 value) {
  
  sequence_ = value;
  // @@protoc_insertion_point(field_set:ClientBuffer.sequence)
}

// string text = 3;
inline void ClientBuffer::clear_text() {
  text_.ClearToEmptyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline const ::std::string& ClientBuffer::text() const {
  // @@protoc_insertion_point(field_get:ClientBuffer.text)
  return text_.GetNoArena();
}
inline void ClientBuffer::set_text(const ::std::string& value) {
  
  text_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), value);
  // @@protoc_insertion_point(field_set:ClientBuffer.text)
}
#if LANG_CXX11
inline void ClientBuffer::set_text(::std::string&& value) {
  
  text_.SetNoArena(
    &::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::move(value));
  // @@protoc_insertion_point(field_set_rvalue:ClientBuffer.text)
}
#endif
inline void ClientBuffer::set_text(const char* value) {
  GOOGLE_DCHECK(value != nullptr);
  
  text_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::string(value));
  // @@protoc_insertion_point(field_set_char:ClientBuffer.text)
}
inline void ClientBuffer::set_text(const char* value, size_t size) {
  
  text_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(),
      ::std::string(reinterpret_cast<const char*>(value), size));
  // @@protoc_insertion_point(field_set_pointer:ClientBuffer.text)
}
inline ::std::string* ClientBuffer::mutable_text() {
  
  // @@protoc_insertion_point(field_mutable:ClientBuffer.text)
  return text_.MutableNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline ::std::string* ClientBuffer::release_text() {
  // @@protoc_insertion_point(field_release:ClientBuffer.text)
  
  return text_.ReleaseNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline void ClientBuffer::set_allocated_text(::std::string* text) {
  if (text != nullptr) {
    
  } else {
    
  }
  text_.SetAllocatedNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), text);
  // @@protoc_insertion_point(field_set_allocated:ClientBuffer.text)
}

// -------------------------------------------------------------------

// ServerBuffer

// uint32 sequence = 1;
inline void ServerBuffer::clear_sequence() {
  sequence_ = 0u;
}
inline ::google::protobuf::uint32 ServerBuffer::sequence() const {
  // @@protoc_insertion_point(field_get:ServerBuffer.sequence)
  return sequence_;
}
inline void ServerBuffer::set_sequence(::google::protobuf::uint32 value) {
  
  sequence_ = value;
  // @@protoc_insertion_point(field_set:ServerBuffer.sequence)
}

#ifdef __GNUC__
  #pragma GCC diagnostic pop
#endif  // __GNUC__
// -------------------------------------------------------------------


// @@protoc_insertion_point(namespace_scope)


// @@protoc_insertion_point(global_scope)

#include <google/protobuf/port_undef.inc>
#endif  // PROTOBUF_INCLUDED_testBuffer_2eproto