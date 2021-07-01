// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: Login.proto

#ifndef PROTOBUF_INCLUDED_Login_2eproto
#define PROTOBUF_INCLUDED_Login_2eproto

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
#define PROTOBUF_INTERNAL_EXPORT_Login_2eproto

// Internal implementation detail -- do not use these members.
struct TableStruct_Login_2eproto {
  static const ::google::protobuf::internal::ParseTableField entries[]
    PROTOBUF_SECTION_VARIABLE(protodesc_cold);
  static const ::google::protobuf::internal::AuxillaryParseTableField aux[]
    PROTOBUF_SECTION_VARIABLE(protodesc_cold);
  static const ::google::protobuf::internal::ParseTable schema[1]
    PROTOBUF_SECTION_VARIABLE(protodesc_cold);
  static const ::google::protobuf::internal::FieldMetadata field_metadata[];
  static const ::google::protobuf::internal::SerializationTable serialization_table[];
  static const ::google::protobuf::uint32 offsets[];
};
void AddDescriptors_Login_2eproto();
class Login;
class LoginDefaultTypeInternal;
extern LoginDefaultTypeInternal _Login_default_instance_;
namespace google {
namespace protobuf {
template<> ::Login* Arena::CreateMaybeMessage<::Login>(Arena*);
}  // namespace protobuf
}  // namespace google

// ===================================================================

class Login :
    public ::google::protobuf::Message /* @@protoc_insertion_point(class_definition:Login) */ {
 public:
  Login();
  virtual ~Login();

  Login(const Login& from);

  inline Login& operator=(const Login& from) {
    CopyFrom(from);
    return *this;
  }
  #if LANG_CXX11
  Login(Login&& from) noexcept
    : Login() {
    *this = ::std::move(from);
  }

  inline Login& operator=(Login&& from) noexcept {
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
  static const Login& default_instance();

  static void InitAsDefaultInstance();  // FOR INTERNAL USE ONLY
  static inline const Login* internal_default_instance() {
    return reinterpret_cast<const Login*>(
               &_Login_default_instance_);
  }
  static constexpr int kIndexInFileMessages =
    0;

  void Swap(Login* other);
  friend void swap(Login& a, Login& b) {
    a.Swap(&b);
  }

  // implements Message ----------------------------------------------

  inline Login* New() const final {
    return CreateMaybeMessage<Login>(nullptr);
  }

  Login* New(::google::protobuf::Arena* arena) const final {
    return CreateMaybeMessage<Login>(arena);
  }
  void CopyFrom(const ::google::protobuf::Message& from) final;
  void MergeFrom(const ::google::protobuf::Message& from) final;
  void CopyFrom(const Login& from);
  void MergeFrom(const Login& from);
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
  void InternalSwap(Login* other);
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

  // string senderCompId = 1;
  void clear_sendercompid();
  static const int kSenderCompIdFieldNumber = 1;
  const ::std::string& sendercompid() const;
  void set_sendercompid(const ::std::string& value);
  #if LANG_CXX11
  void set_sendercompid(::std::string&& value);
  #endif
  void set_sendercompid(const char* value);
  void set_sendercompid(const char* value, size_t size);
  ::std::string* mutable_sendercompid();
  ::std::string* release_sendercompid();
  void set_allocated_sendercompid(::std::string* sendercompid);

  // string targetCompId = 2;
  void clear_targetcompid();
  static const int kTargetCompIdFieldNumber = 2;
  const ::std::string& targetcompid() const;
  void set_targetcompid(const ::std::string& value);
  #if LANG_CXX11
  void set_targetcompid(::std::string&& value);
  #endif
  void set_targetcompid(const char* value);
  void set_targetcompid(const char* value, size_t size);
  ::std::string* mutable_targetcompid();
  ::std::string* release_targetcompid();
  void set_allocated_targetcompid(::std::string* targetcompid);

  // uint32 heartBt = 3;
  void clear_heartbt();
  static const int kHeartBtFieldNumber = 3;
  ::google::protobuf::uint32 heartbt() const;
  void set_heartbt(::google::protobuf::uint32 value);

  // @@protoc_insertion_point(class_scope:Login)
 private:
  class HasBitSetters;

  ::google::protobuf::internal::InternalMetadataWithArena _internal_metadata_;
  ::google::protobuf::internal::ArenaStringPtr sendercompid_;
  ::google::protobuf::internal::ArenaStringPtr targetcompid_;
  ::google::protobuf::uint32 heartbt_;
  mutable ::google::protobuf::internal::CachedSize _cached_size_;
  friend struct ::TableStruct_Login_2eproto;
};
// ===================================================================


// ===================================================================

#ifdef __GNUC__
  #pragma GCC diagnostic push
  #pragma GCC diagnostic ignored "-Wstrict-aliasing"
#endif  // __GNUC__
// Login

// string senderCompId = 1;
inline void Login::clear_sendercompid() {
  sendercompid_.ClearToEmptyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline const ::std::string& Login::sendercompid() const {
  // @@protoc_insertion_point(field_get:Login.senderCompId)
  return sendercompid_.GetNoArena();
}
inline void Login::set_sendercompid(const ::std::string& value) {
  
  sendercompid_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), value);
  // @@protoc_insertion_point(field_set:Login.senderCompId)
}
#if LANG_CXX11
inline void Login::set_sendercompid(::std::string&& value) {
  
  sendercompid_.SetNoArena(
    &::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::move(value));
  // @@protoc_insertion_point(field_set_rvalue:Login.senderCompId)
}
#endif
inline void Login::set_sendercompid(const char* value) {
  GOOGLE_DCHECK(value != nullptr);
  
  sendercompid_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::string(value));
  // @@protoc_insertion_point(field_set_char:Login.senderCompId)
}
inline void Login::set_sendercompid(const char* value, size_t size) {
  
  sendercompid_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(),
      ::std::string(reinterpret_cast<const char*>(value), size));
  // @@protoc_insertion_point(field_set_pointer:Login.senderCompId)
}
inline ::std::string* Login::mutable_sendercompid() {
  
  // @@protoc_insertion_point(field_mutable:Login.senderCompId)
  return sendercompid_.MutableNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline ::std::string* Login::release_sendercompid() {
  // @@protoc_insertion_point(field_release:Login.senderCompId)
  
  return sendercompid_.ReleaseNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline void Login::set_allocated_sendercompid(::std::string* sendercompid) {
  if (sendercompid != nullptr) {
    
  } else {
    
  }
  sendercompid_.SetAllocatedNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), sendercompid);
  // @@protoc_insertion_point(field_set_allocated:Login.senderCompId)
}

// string targetCompId = 2;
inline void Login::clear_targetcompid() {
  targetcompid_.ClearToEmptyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline const ::std::string& Login::targetcompid() const {
  // @@protoc_insertion_point(field_get:Login.targetCompId)
  return targetcompid_.GetNoArena();
}
inline void Login::set_targetcompid(const ::std::string& value) {
  
  targetcompid_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), value);
  // @@protoc_insertion_point(field_set:Login.targetCompId)
}
#if LANG_CXX11
inline void Login::set_targetcompid(::std::string&& value) {
  
  targetcompid_.SetNoArena(
    &::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::move(value));
  // @@protoc_insertion_point(field_set_rvalue:Login.targetCompId)
}
#endif
inline void Login::set_targetcompid(const char* value) {
  GOOGLE_DCHECK(value != nullptr);
  
  targetcompid_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::string(value));
  // @@protoc_insertion_point(field_set_char:Login.targetCompId)
}
inline void Login::set_targetcompid(const char* value, size_t size) {
  
  targetcompid_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(),
      ::std::string(reinterpret_cast<const char*>(value), size));
  // @@protoc_insertion_point(field_set_pointer:Login.targetCompId)
}
inline ::std::string* Login::mutable_targetcompid() {
  
  // @@protoc_insertion_point(field_mutable:Login.targetCompId)
  return targetcompid_.MutableNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline ::std::string* Login::release_targetcompid() {
  // @@protoc_insertion_point(field_release:Login.targetCompId)
  
  return targetcompid_.ReleaseNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline void Login::set_allocated_targetcompid(::std::string* targetcompid) {
  if (targetcompid != nullptr) {
    
  } else {
    
  }
  targetcompid_.SetAllocatedNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), targetcompid);
  // @@protoc_insertion_point(field_set_allocated:Login.targetCompId)
}

// uint32 heartBt = 3;
inline void Login::clear_heartbt() {
  heartbt_ = 0u;
}
inline ::google::protobuf::uint32 Login::heartbt() const {
  // @@protoc_insertion_point(field_get:Login.heartBt)
  return heartbt_;
}
inline void Login::set_heartbt(::google::protobuf::uint32 value) {
  
  heartbt_ = value;
  // @@protoc_insertion_point(field_set:Login.heartBt)
}

#ifdef __GNUC__
  #pragma GCC diagnostic pop
#endif  // __GNUC__

// @@protoc_insertion_point(namespace_scope)


// @@protoc_insertion_point(global_scope)

#include <google/protobuf/port_undef.inc>
#endif  // PROTOBUF_INCLUDED_Login_2eproto