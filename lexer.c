#include "utils.h"
#include "tokenlinkedlist.h"

#define MAXCHAR 1000

void tokeniseSourcecode(char* filename, tokenStream** s)
{
	FILE* FILEIN = fopen(filename, "r");
	// char[1000] line;
	// fscanf(fptr, "%[^\n]", line);
	// char *token = strtok(string, " ");
	char* line;
	int lineNumber=1;

	while (fgets(line,MAXCHAR,FILEIN))
	{
		char *lexeme = strtok(line, " ");

		while(lexeme != NULL) {

			int id;
			identify_token(lexeme, &id);
			tokenStreamNode* node = createTokenStreamNode(id, lexeme, lineNumber);
			addToken(*s, node);
      		lexeme = strtok(NULL, " "); //next token
      	}

      	lineNumber++;
	}

	fclose(FILEIN);
}



