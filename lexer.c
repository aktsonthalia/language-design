/* 

Group: 45

Members:

V. Aravindan 		: 		2017B4A70849P
Ankit Sonthalia 	:		2017B4A70468P
Rohit K Bharadwaj   :		2017B4A70633P
Ritik Bavdekar      :     	2017B4A70349P

*/
#include "utils.h"
#include "lexer.h"

#define MAXCHAR 1000 

void tokeniseSourcecode(char* filename, tokenStream* s)
{
	FILE* FILEIN = fopen(filename, "r");
	char line[MAXCHAR];
	int lineNumber=1;


	while (fgets(line, MAXCHAR, FILEIN))
	{


		int idx = strlen(line)-1;
		if(line[idx] == '\n')
			line[idx] = '\0';

		if(!line)
			continue;
		
		char *lexeme = strtok(line, " ");
		strip(lexeme);
		

		while(lexeme != NULL) {

			int id;
			identify_token(lexeme, &id);
			tokenStreamNode* node = createTokenStreamNode(id, lexeme, lineNumber);
			addToken(s, node);
      		lexeme = strtok(NULL, " "); //next token
      	}

      	lineNumber++;
	}

	fclose(FILEIN);
}



