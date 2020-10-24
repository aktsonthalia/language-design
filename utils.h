#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>
#include <sys/stat.h>
#include <limits.h>

extern char delimiter[];
extern int countLines(char* filename);
char *ltrim(char *s);

char *rtrim(char *s);

char *trim(char *s);
void removeSpaces(char *str);

void createCache();

void replace(char* nt, int* a, int* b);
