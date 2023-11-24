#include <memory.h>
#include <stdlib.h>

void* reallocate(void* pointer, size_t old_size, size_t new_size) {
	if (new_size == 0) {
		free(pointer);
		return NULL;
	}

	void* result = realloc(pointer, new_size); //when old_size != 0 && new_size != 0, realloc resize previously allocated blocks
	if (result == NULL) exit(1); //if not enough memory, handle allocation failure by aborting
	return result;
}
