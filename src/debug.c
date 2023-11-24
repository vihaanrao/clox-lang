#include <stdio.h>

#include "debug.h"

void disassemble_chunk(Chunk *chunk, const char *name) {
  printf("== %s == \n", name);

  for (int offset = 0; offset < chunk->count;) {
    offset = disassemble_instruction(chunk, offset);
  }
}

