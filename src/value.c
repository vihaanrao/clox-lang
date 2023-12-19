#include <stdio.h>

#include "memory.h" 
#include "value.h"

void init_value_array(value_array *array) {
  array->value = NULL;
  array->capacity = 0;
  array->count = 0;
}

void write_value_array(value_array *array, Value value) {
  if (array->capacity < array->count + 1) {
    int old_capacity = array->capacity;
    array->capacity = GROW_CAPACITY(old_capacity);
    array->value = GROW_ARRAY(Value, array->value, old_capacity, array->capacity);
  }

  array->value[array->count] = value;
  array->count++;
}

void free_value_array(value_array *array) {
  FREE_ARRAY(Value, array->value, array->capacity);
  init_value_array(array);
}
