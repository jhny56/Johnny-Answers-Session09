// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from cpp_turtle:srv/FindWall.idl
// generated code does not contain a copyright notice

#ifndef CPP_TURTLE__SRV__DETAIL__FIND_WALL__BUILDER_HPP_
#define CPP_TURTLE__SRV__DETAIL__FIND_WALL__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "cpp_turtle/srv/detail/find_wall__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace cpp_turtle
{

namespace srv
{


}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::cpp_turtle::srv::FindWall_Request>()
{
  return ::cpp_turtle::srv::FindWall_Request(rosidl_runtime_cpp::MessageInitialization::ZERO);
}

}  // namespace cpp_turtle


namespace cpp_turtle
{

namespace srv
{

namespace builder
{

class Init_FindWall_Response_success
{
public:
  Init_FindWall_Response_success()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::cpp_turtle::srv::FindWall_Response success(::cpp_turtle::srv::FindWall_Response::_success_type arg)
  {
    msg_.success = std::move(arg);
    return std::move(msg_);
  }

private:
  ::cpp_turtle::srv::FindWall_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::cpp_turtle::srv::FindWall_Response>()
{
  return cpp_turtle::srv::builder::Init_FindWall_Response_success();
}

}  // namespace cpp_turtle

#endif  // CPP_TURTLE__SRV__DETAIL__FIND_WALL__BUILDER_HPP_
