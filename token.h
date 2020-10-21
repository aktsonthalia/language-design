#include "utils.h"



typedef struct
{
	char* lexeme;
	char* symbol;
}token;

extern int numtokens;
extern token tokens[29];

void identify_token(char* lexeme, int* index);
