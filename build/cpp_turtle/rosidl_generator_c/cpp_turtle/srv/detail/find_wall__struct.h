// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from cpp_turtle:srv/FindWall.idl
// generated code does not contain a copyright notice

#ifndef CPP_TURTLE__SRV__DETAIL__FIND_WALL__STRUCT_H_
#define CPP_TURTLE__SRV__DETAIL__FIND_WALL__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Struct defined in srv/FindWall in the package cpp_turtle.
typedef struct cpp_turtle__srv__FindWall_Request
{
  uint8_t structure_needs_at_least_one_member;
} cpp_turtle__srv__FindWall_Request;

// Struct for a sequence of cpp_turtle__srv__FindWall_Request.
typedef struct cpp_turtle__srv__FindWall_Request__Sequence
{
  cpp_turtle__srv__FindWall_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} cpp_turtle__srv__FindWall_Request__Sequence;


// Constants defined in the message

/// Struct defined in srv/FindWall in the package cpp_turtle.
typedef struct cpp_turtle__srv__FindWall_Response
{
  bool success;
} cpp_turtle__srv__FindWall_Response;

// Struct for a sequence of cpp_turtle__srv__FindWall_Response.
typedef struct cpp_turtle__srv__FindWall_Response__Sequence
{
  cpp_turtle__srv__FindWall_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} cpp_turtle__srv__FindWall_Response__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // CPP_TURTLE__SRV__DETAIL__FIND_WALL__STRUCT_H_
