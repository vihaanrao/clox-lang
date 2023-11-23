#ifndef clox_chunk_h
#define clox_chunk_h

#include "common.h"

typedef enum {
	OP_RETURN,
} OpCode;

typedef struct { //dynamic arr as a wrapper to store bytes 
	int count;
	int capacity;
	uint8_t* code; //ptr to the array
} Chunk;

void init_chunk(Chunk* chunk);
void write_chunk(Chunk* chunk, uint8_t byte);
#endif 
