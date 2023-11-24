#ifndef clox_memory_h
#define clox_memory_h

#include "common.h"
#include <stddef.h>

#define GROW_CAPACITY(capacity) \
    ((capacity) < 8 ? 8 : (capacity) * 2)

#define GROW_ARRAY(type, pointer, old_count, new_count) \
    (type*)reallocate(pointer, sizeof(type) * (old_count), sizeof(type) * (new_count)) //macro takes care of casting void* from reallocate to ptr of right type

#define FREE_ARRAY(type, pointer, old_count) \
    reallocate(pointer, sizeof(type) * (old_count), 0)
/*
 reallocate behavior:

old_size 	new_size		Operation
  0		non‑zero		alloc new block.
  non‑zero 	0			free alloc.
  non‑zero 	smaller than old_size	shrink existing alloc.
  non‑zero 	larger than old_size 	grow existing alloc.  
*/

void* reallocate(void* pointer, size_t old_size, size_t new_size); //routing dynamic memory ops through single fn
#endif 
