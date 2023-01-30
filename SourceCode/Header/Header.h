#ifndef SOURCECODE_HEADER_H
#define SOURCECODE_HEADER_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <limits.h>

void errorHandeling(long int a, const char *argv, const char *endptr);
void separateString(int amount, char *del, char *input);
char *lineRead(FILE * In, int strL);
void openFiles(int amountt);
void closeFiles(int amount);
int get_string_length(const char *filename);
int count_delimiter(const char *filename, const char *delim);

extern const char *outputpath;
extern const char *inputFile;

extern FILE *output[9], *Input;

#endif //SOURCECODE_HEADER_H
