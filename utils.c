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