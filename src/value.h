#ifndef clox_value_h
#define clox_value_h

#include "common.h"

typedef double Value;

typedef struct {
	int capacity;
	int count;
	Value* value;
} value_array;

void init_value_arry(value_array* array);
void write_value_array(value_array* array, Value value);
void free_value_array(value_array* array);

#endif // !clox_value_h
