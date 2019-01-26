#ifndef CONVERTER_H
#define CONVERTER_H

#include <stdio.h>
#include <stdlib.h>
#include <math.h>


#define READ_BIT(b, p) ((b) >> (p)) & ((1 << 1) - 1) // lit un bit a la position p de la variable b

typedef struct bitset{

  char* bits;
  size_t n;
  
} bitset;

int bitset_to_int (bitset*);

bitset* bytes_to_bitset (char);

char bitset_to_bytes (bitset* );

#endif
