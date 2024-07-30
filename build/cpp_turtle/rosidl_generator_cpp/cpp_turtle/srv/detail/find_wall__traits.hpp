// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from cpp_turtle:srv/FindWall.idl
// generated code does not contain a copyright notice

#ifndef CPP_TURTLE__SRV__DETAIL__FIND_WALL__TRAITS_HPP_
#define CPP_TURTLE__SRV__DETAIL__FIND_WALL__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "cpp_turtle/srv/detail/find_wall__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace cpp_turtle
{

namespace srv
{

inline void to_flow_style_yaml(
  const FindWall_Request & msg,
  std::ostream & out)
{
  (void)msg;
  out << "null";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const FindWall_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  (void)msg;
  (void)indentation;
  out << "null\n";
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const FindWall_Request & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace srv

}  // namespace cpp_turtle

namespace rosidl_generator_traits
{

[[deprecated("use cpp_turtle::srv::to_block_style_yaml() instead")]]
inline void to_yaml(
  const cpp_turtle::srv::FindWall_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  cpp_turtle::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use cpp_turtle::srv::to_yaml() instead")]]
inline std::string to_yaml(const cpp_turtle::srv::FindWall_Request & msg)
{
  return cpp_turtle::srv::to_yaml(msg);
}

template<>
inline const char * data_type<cpp_turtle::srv::FindWall_Request>()
{
  return "cpp_turtle::srv::FindWall_Request";
}

template<>
inline const char * name<cpp_turtle::srv::FindWall_Request>()
{
  return "cpp_turtle/srv/FindWall_Request";
}

template<>
struct has_fixed_size<cpp_turtle::srv::FindWall_Request>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<cpp_turtle::srv::FindWall_Request>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<cpp_turtle::srv::FindWall_Request>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace cpp_turtle
{

namespace srv
{

inline void to_flow_style_yaml(
  const FindWall_Response & msg,
  std::ostream & out)
{
  out << "{";
  // member: success
  {
    out << "success: ";
    rosidl_generator_traits::value_to_yaml(msg.success, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const FindWall_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: success
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "success: ";
    rosidl_generator_traits::value_to_yaml(msg.success, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const FindWall_Response & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace srv

}  // namespace cpp_turtle

namespace rosidl_generator_traits
{

[[deprecated("use cpp_turtle::srv::to_block_style_yaml() instead")]]
inline void to_yaml(
  const cpp_turtle::srv::FindWall_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  cpp_turtle::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use cpp_turtle::srv::to_yaml() instead")]]
inline std::string to_yaml(const cpp_turtle::srv::FindWall_Response & msg)
{
  return cpp_turtle::srv::to_yaml(msg);
}

template<>
inline const char * data_type<cpp_turtle::srv::FindWall_Response>()
{
  return "cpp_turtle::srv::FindWall_Response";
}

template<>
inline const char * name<cpp_turtle::srv::FindWall_Response>()
{
  return "cpp_turtle/srv/FindWall_Response";
}

template<>
struct has_fixed_size<cpp_turtle::srv::FindWall_Response>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<cpp_turtle::srv::FindWall_Response>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<cpp_turtle::srv::FindWall_Response>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<cpp_turtle::srv::FindWall>()
{
  return "cpp_turtle::srv::FindWall";
}

template<>
inline const char * name<cpp_turtle::srv::FindWall>()
{
  return "cpp_turtle/srv/FindWall";
}

template<>
struct has_fixed_size<cpp_turtle::srv::FindWall>
  : std::integral_constant<
    bool,
    has_fixed_size<cpp_turtle::srv::FindWall_Request>::value &&
    has_fixed_size<cpp_turtle::srv::FindWall_Response>::value
  >
{
};

template<>
struct has_bounded_size<cpp_turtle::srv::FindWall>
  : std::integral_constant<
    bool,
    has_bounded_size<cpp_turtle::srv::FindWall_Request>::value &&
    has_bounded_size<cpp_turtle::srv::FindWall_Response>::value
  >
{
};

template<>
struct is_service<cpp_turtle::srv::FindWall>
  : std::true_type
{
};

template<>
struct is_service_request<cpp_turtle::srv::FindWall_Request>
  : std::true_type
{
};

template<>
struct is_service_response<cpp_turtle::srv::FindWall_Response>
  : std::true_type
{
};

}  // namespace rosidl_generator_traits

#endif  // CPP_TURTLE__SRV__DETAIL__FIND_WALL__TRAITS_HPP_
