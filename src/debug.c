#include <stdint.h>
#include <stdio.h>

#include "chunk.h"
#include "debug.h"
#include "value.h"

void disassemble_chunk(Chunk *chunk, const char *name) {
  printf("== %s == \n", name);

  for (int offset = 0; offset < chunk->count;) {
    offset = disassemble_instruction(chunk, offset);
  }
}

int disassemble_instruction(Chunk *chunk, int offset) {
  printf("%04d ", offset);

  uint8_t instruction = chunk->code[offset];
  switch (instruction) {
  case OP_CONSTANT:
    return constant_instruction("OP_CONSTANT", chunk, offset);
  case OP_RETURN:
    return simple_instruction("OP_RETURN", offset);
  default:
    printf("Unkown opcode %d\n", instruction);
    return offset + 1;
  }
}

static int simple_instruction(const char *name, int offset) {
  printf("%s\n", name);
  return offset + 1;
}

/*
 * Print the name of the opcode and pull constant index from next byte in chunk.
 * Also lookup actual constant value and display it.
 */
static int constant_instruction(const char *name, Chunk *chunk, int offset) {
  uint8_t constant = chunk->code[offset + 1];
  /*
   * - : left justification
   * 16: string will take at least 16 chars
   * 4 : width of integer field
   */
  printf("%-16s %4d '", name, constant);
  print_value(chunk->constants.value[constant]);
  printf("\n");
  return offset + 2;
}
