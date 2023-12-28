#ifndef clox_chunk_h
#define clox_chunk_h

#include "common.h"
#include "value.h"

typedef enum {
  OP_RETURN,
  OP_CONSTANT,
} OpCode;

typedef struct { // Dynamic array as a wrapper to store bytes
  int count;
  int capacity;
  uint8_t *code; // Pointer to the array
  int *lines;    // Each int in array parallels bytecode
  value_array constants;
} Chunk;

void init_chunk(Chunk *chunk);
void free_chunk(Chunk *chunk);
void write_chunk(Chunk *chunk, uint8_t byte, int line);
int add_const(Chunk *chunk, Value value);
#endif
