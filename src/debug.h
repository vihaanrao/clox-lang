#ifndef clox_debug_h
#define clox_debug_h

#include "chunk.h"

void disassemble_chunk(Chunk* chunk, const char* name);
int disassemble_instruction(Chunk*, int offset);

#endif // !clox_debug_h
#define clox_debug_h

