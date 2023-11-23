#ifndef clox_memory_h
#define clox_memory_h

#include "common.h"

#define GROW_CAPACITY(capacity) \ ((capacity) < 8 ? 8 : (capacity * 2)) //macro to grow capacity if < 8 bytes

#define GROW_ARRAY(type, pointer, old_count, new_count) \ (type*)reallocate(pointer, sizeof(type) * old_count), \
		  sizeof(type) * (new_count))

void* reallocate(void* pointer, size_t old_size, size_t new_size);
#endif 
