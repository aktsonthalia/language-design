#include "utils.h"

int countLines(char* filename)
{
	FILE* fp = fopen(filename, "r");

	char* line = NULL;
	size_t len = 0; //len = 0;
	int n = 0;

	while(getline(&line, &len, fp) != -1)
	{
		if(line)
			n++;
	}

	fclose(fp);
	return n;
}

char *ltrim(char *s)
{
    while(isspace(*s)) s++;
    return s;
}

char *rtrim(char *s)
{
    char* back = s + strlen(s);
    while(isspace(*--back));
    *(back+1) = '\0';
    return s;
}

char *trim(char *s)
{
    return rtrim(ltrim(s)); 
}

void removeSpaces(char *str) 
{ 
    // To keep track of non-space character count 
    int count = 0; 
  
    // Traverse the given string. If current character 
    // is not space, then place it at index 'count++' 
    for (int i = 0; str[i]; i++) 
        if (str[i] != ' ') 
            str[count++] = str[i]; // here count is 
                                   // incremented 
    str[count] = '\0'; 
} 