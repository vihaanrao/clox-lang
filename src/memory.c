#include <stdio.h>
#include <stdlib.h>

#include "memory.h"

void* reallocate(void* pointer, size_t old_size, size_t new_size) {
	if (new_size == 0) {
		free(pointer);
		return NULL;
	}

	void* result = realloc(pointer, new_size); //when old_size != 0 && new_size != 0, realloc resize previously allocated blocks
	if (result == NULL) {
		fprintf(stderr, "Out of memory! Cannot allocate %zu bytes\n", new_size);
	} //if not enough memory, handle allocation failure by printing out error
	return result;
}
