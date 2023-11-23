#include <stdint.h>
#include <stdlib.h>

#include "chunk.h"
#include "memory.h"
void init_chunk(Chunk *chunk) {
	chunk->count = 0;
	chunk->capacity = 0;
	chunk->code = NULL;
}

void write_chunk(Chunk *chunk, uint8_t byte) {
	if (chunk->capacity < chunk->capacity + 1) { //check if curr arr has capacity for new byte
		int old_capacity = chunk->capacity;
		chunk->capacity = GROW_CAPACTIY(old_capacity);
		chunk->code = GROW_ARRAY(uint8_t, chunk->code, old_capacity, chunk->capacity);
	}

	chunk->code[chunk->count] = byte;
	chunk->count++;
}
