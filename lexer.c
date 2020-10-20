#include <ctype.h>
#include <string.h>
#include "tokenlinkedlist.h"
#include "token.h"
#include <stdio.h>
#define MAXCHAR 1000

void tokeniseSourcecode( char* filename, linkedlist *s)
{
	FILE* FILEIN=fopen(filename,'r');
	// char[1000] line;
	// fscanf(fptr, "%[^\n]", line);
	// char *token = strtok(string, " ");
	char [MAXCHAR] line;
	int lineNumber=1;
	while (fgets(line,MAXCHAR,FILEIN))
	{
		char *lexeme = strtok(line," ");
		while(  lexeme != NULL ) {
      		token t_name=identify_token(lexeme);
      		addTokenLinkedList(s,t_name,lexeme,lineNumber);
      		lexeme = strtok(NULL, " ");//next token
      	}
      	lineNumber++;
	}
	fclose(FILEIN);
	return;
}
