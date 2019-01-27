#ifndef FILE_READER_H
#define FILE_READER_H

#include "./converter.h"

char* read (char*, int);

FILE* open_file (char*, FILE*);

int read_n_bytes (FILE*, int, char*);

#endif
