/* 

Group: 45

Members:

V. Aravindan 		: 		2017B4A70849P
Ankit Sonthalia 	:		2017B4A70468P
Rohit K Bharadwaj   :		2017B4A70633P
Ritik Bavdekar      :     	2017B4A70349P

*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>
#include <sys/stat.h>
#include <limits.h>

#ifndef structures_h
#define structures_h
#include "structures.h"
#endif


extern char delimiter[];
extern int countLines(char* filename);
char *ltrim(char *s);

char *rtrim(char *s);

char *trim(char *s);
void removeSpaces(char *str);

void createCache();

void getNTCache(char* nt, int* a, int* b);
void strip(char *text);
void cleanWhiteSpaces(char* filename);
int isTerminal(char* symbol);
