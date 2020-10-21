#include "utils.h"
#include "token.h"

void identify_token(char* lexeme, int* index)
{
    for(int i=0; i<numtokens; i++)
    {
        if(strcmp(lexeme, tokens[i].symbol) == 0)
        {
            *index = i;
            return;
        }
    }

    char c1[] = "<var_name>";
    char c2[] = "<const>";

    if(isdigit(lexeme[0]))
        *index = numtokens-2;

    else
        *index = numtokens-1;
}



