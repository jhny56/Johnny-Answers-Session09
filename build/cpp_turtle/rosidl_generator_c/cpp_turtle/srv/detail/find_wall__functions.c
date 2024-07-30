// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from cpp_turtle:srv/FindWall.idl
// generated code does not contain a copyright notice
#include "cpp_turtle/srv/detail/find_wall__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"

bool
cpp_turtle__srv__FindWall_Request__init(cpp_turtle__srv__FindWall_Request * msg)
{
  if (!msg) {
    return false;
  }
  // structure_needs_at_least_one_member
  return true;
}

void
cpp_turtle__srv__FindWall_Request__fini(cpp_turtle__srv__FindWall_Request * msg)
{
  if (!msg) {
    return;
  }
  // structure_needs_at_least_one_member
}

bool
cpp_turtle__srv__FindWall_Request__are_equal(const cpp_turtle__srv__FindWall_Request * lhs, const cpp_turtle__srv__FindWall_Request * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // structure_needs_at_least_one_member
  if (lhs->structure_needs_at_least_one_member != rhs->structure_needs_at_least_one_member) {
    return false;
  }
  return true;
}

bool
cpp_turtle__srv__FindWall_Request__copy(
  const cpp_turtle__srv__FindWall_Request * input,
  cpp_turtle__srv__FindWall_Request * output)
{
  if (!input || !output) {
    return false;
  }
  // structure_needs_at_least_one_member
  output->structure_needs_at_least_one_member = input->structure_needs_at_least_one_member;
  return true;
}

cpp_turtle__srv__FindWall_Request *
cpp_turtle__srv__FindWall_Request__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  cpp_turtle__srv__FindWall_Request * msg = (cpp_turtle__srv__FindWall_Request *)allocator.allocate(sizeof(cpp_turtle__srv__FindWall_Request), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(cpp_turtle__srv__FindWall_Request));
  bool success = cpp_turtle__srv__FindWall_Request__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
cpp_turtle__srv__FindWall_Request__destroy(cpp_turtle__srv__FindWall_Request * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    cpp_turtle__srv__FindWall_Request__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
cpp_turtle__srv__FindWall_Request__Sequence__init(cpp_turtle__srv__FindWall_Request__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  cpp_turtle__srv__FindWall_Request * data = NULL;

  if (size) {
    data = (cpp_turtle__srv__FindWall_Request *)allocator.zero_allocate(size, sizeof(cpp_turtle__srv__FindWall_Request), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = cpp_turtle__srv__FindWall_Request__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        cpp_turtle__srv__FindWall_Request__fini(&data[i - 1]);
      }
      allocator.deallocate(data, allocator.state);
      return false;
    }
  }
  array->data = data;
  array->size = size;
  array->capacity = size;
  return true;
}

void
cpp_turtle__srv__FindWall_Request__Sequence__fini(cpp_turtle__srv__FindWall_Request__Sequence * array)
{
  if (!array) {
    return;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();

  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      cpp_turtle__srv__FindWall_Request__fini(&array->data[i]);
    }
    allocator.deallocate(array->data, allocator.state);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
  } else {
    // ensure that data, size, and capacity values are consistent
    assert(0 == array->size);
    assert(0 == array->capacity);
  }
}

cpp_turtle__srv__FindWall_Request__Sequence *
cpp_turtle__srv__FindWall_Request__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  cpp_turtle__srv__FindWall_Request__Sequence * array = (cpp_turtle__srv__FindWall_Request__Sequence *)allocator.allocate(sizeof(cpp_turtle__srv__FindWall_Request__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = cpp_turtle__srv__FindWall_Request__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
cpp_turtle__srv__FindWall_Request__Sequence__destroy(cpp_turtle__srv__FindWall_Request__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    cpp_turtle__srv__FindWall_Request__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
cpp_turtle__srv__FindWall_Request__Sequence__are_equal(const cpp_turtle__srv__FindWall_Request__Sequence * lhs, const cpp_turtle__srv__FindWall_Request__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!cpp_turtle__srv__FindWall_Request__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
cpp_turtle__srv__FindWall_Request__Sequence__copy(
  const cpp_turtle__srv__FindWall_Request__Sequence * input,
  cpp_turtle__srv__FindWall_Request__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(cpp_turtle__srv__FindWall_Request);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    cpp_turtle__srv__FindWall_Request * data =
      (cpp_turtle__srv__FindWall_Request *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!cpp_turtle__srv__FindWall_Request__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          cpp_turtle__srv__FindWall_Request__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!cpp_turtle__srv__FindWall_Request__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}


bool
cpp_turtle__srv__FindWall_Response__init(cpp_turtle__srv__FindWall_Response * msg)
{
  if (!msg) {
    return false;
  }
  // success
  return true;
}

void
cpp_turtle__srv__FindWall_Response__fini(cpp_turtle__srv__FindWall_Response * msg)
{
  if (!msg) {
    return;
  }
  // success
}

bool
cpp_turtle__srv__FindWall_Response__are_equal(const cpp_turtle__srv__FindWall_Response * lhs, const cpp_turtle__srv__FindWall_Response * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // success
  if (lhs->success != rhs->success) {
    return false;
  }
  return true;
}

bool
cpp_turtle__srv__FindWall_Response__copy(
  const cpp_turtle__srv__FindWall_Response * input,
  cpp_turtle__srv__FindWall_Response * output)
{
  if (!input || !output) {
    return false;
  }
  // success
  output->success = input->success;
  return true;
}

cpp_turtle__srv__FindWall_Response *
cpp_turtle__srv__FindWall_Response__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  cpp_turtle__srv__FindWall_Response * msg = (cpp_turtle__srv__FindWall_Response *)allocator.allocate(sizeof(cpp_turtle__srv__FindWall_Response), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(cpp_turtle__srv__FindWall_Response));
  bool success = cpp_turtle__srv__FindWall_Response__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
cpp_turtle__srv__FindWall_Response__destroy(cpp_turtle__srv__FindWall_Response * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    cpp_turtle__srv__FindWall_Response__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
cpp_turtle__srv__FindWall_Response__Sequence__init(cpp_turtle__srv__FindWall_Response__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  cpp_turtle__srv__FindWall_Response * data = NULL;

  if (size) {
    data = (cpp_turtle__srv__FindWall_Response *)allocator.zero_allocate(size, sizeof(cpp_turtle__srv__FindWall_Response), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = cpp_turtle__srv__FindWall_Response__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        cpp_turtle__srv__FindWall_Response__fini(&data[i - 1]);
      }
      allocator.deallocate(data, allocator.state);
      return false;
    }
  }
  array->data = data;
  array->size = size;
  array->capacity = size;
  return true;
}

void
cpp_turtle__srv__FindWall_Response__Sequence__fini(cpp_turtle__srv__FindWall_Response__Sequence * array)
{
  if (!array) {
    return;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();

  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      cpp_turtle__srv__FindWall_Response__fini(&array->data[i]);
    }
    allocator.deallocate(array->data, allocator.state);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
  } else {
    // ensure that data, size, and capacity values are consistent
    assert(0 == array->size);
    assert(0 == array->capacity);
  }
}

cpp_turtle__srv__FindWall_Response__Sequence *
cpp_turtle__srv__FindWall_Response__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  cpp_turtle__srv__FindWall_Response__Sequence * array = (cpp_turtle__srv__FindWall_Response__Sequence *)allocator.allocate(sizeof(cpp_turtle__srv__FindWall_Response__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = cpp_turtle__srv__FindWall_Response__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
cpp_turtle__srv__FindWall_Response__Sequence__destroy(cpp_turtle__srv__FindWall_Response__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    cpp_turtle__srv__FindWall_Response__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
cpp_turtle__srv__FindWall_Response__Sequence__are_equal(const cpp_turtle__srv__FindWall_Response__Sequence * lhs, const cpp_turtle__srv__FindWall_Response__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!cpp_turtle__srv__FindWall_Response__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
cpp_turtle__srv__FindWall_Response__Sequence__copy(
  const cpp_turtle__srv__FindWall_Response__Sequence * input,
  cpp_turtle__srv__FindWall_Response__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(cpp_turtle__srv__FindWall_Response);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    cpp_turtle__srv__FindWall_Response * data =
      (cpp_turtle__srv__FindWall_Response *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!cpp_turtle__srv__FindWall_Response__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          cpp_turtle__srv__FindWall_Response__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!cpp_turtle__srv__FindWall_Response__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}