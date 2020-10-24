#include "utils.h"

char delimiter[2] = " ";

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

// char delimiter[2] = " ";
char dirName[NAME_MAX+1];

void createFile(char* realToken, int lineIdx, int countToken) {



        char *prefix = "non-terminals";

        snprintf(dirName, NAME_MAX + 1,"%s", prefix);
        //printf("%s\n",dirName);
        struct stat st = {0};

        if (stat(dirName, &st) == -1) {              //Directory does not exist, create it.
                if(mkdir(dirName, 0755) != -1){            // created directory
                char fPath[PATH_MAX+1];             // file path
                snprintf(fPath, PATH_MAX + 1, "%s/%s", dirName, realToken);

                FILE *fp = fopen(fPath, "w");
                fprintf(fp, "%d %d", lineIdx, countToken);
                fclose(fp);
                }else{
                perror("mkdir: ");
                }
        } else {
                char fPath[PATH_MAX+1];             // file path
                snprintf(fPath, PATH_MAX + 1, "%s/%s", dirName, realToken);

                FILE *fp = fopen(fPath, "w");
                fprintf(fp, "%d %d", lineIdx, countToken);
                fclose(fp);
        }
}

char* getRealToken(char* token) {
                int currSize = 0;

                while (token[currSize] != '>') {
                        currSize++;
                }
                char* realToken = (char*) malloc(sizeof(char)*(currSize+3));
                int cnter = 0;
                for (int i = 0; i < currSize+1; i++) {
                        if (i != 0 && i != currSize) {
                              realToken[cnter] = token[i];
                              cnter++;
                        }
                }
                realToken[cnter] = '.';
                cnter++;
                realToken[cnter] = 'n';
                cnter++;
                realToken[cnter] = 't';
                cnter++;
                realToken[cnter] = '\0';
                return realToken;
}

void createCache() 
{
        FILE* fp = fopen("grammar.txt", "r");
        char* line = NULL;
    size_t len = 0;
        int n = countLines("grammar.txt");
    int lineIdx = 0;
        int countToken = 1;
        char oldToken[100];
        for(int i=0; i<n; i++)
    {

                getline(&line, &len, fp);

        //removing newline character
        line[strlen(line)-1] = '\0';

                char* token = strtok(line, delimiter);
                char* realToken;
                realToken = getRealToken(token);


                if (i != 0) {

                        if (strcmp(realToken, oldToken) == 0) {
                                countToken++;
                        } else {
                                countToken = 1;
                                lineIdx = i;
                        }

                        strcpy(oldToken, realToken);
                        createFile(realToken, lineIdx, countToken);



                } else {

                        strcpy(oldToken, realToken);
                        createFile(realToken, lineIdx, countToken);


                }

    }


}



void replace(char* nt, int* a, int* b) 
{
 // pass reference of integer when calling the function.
            char* realToken;
                realToken = getRealToken(nt);

                char *prefix = "non-terminals";

                snprintf(dirName, NAME_MAX + 1,"%s", prefix);

                char fPath[PATH_MAX+1];             // file path
                //printf("DirName: %s\n", dirName);
                snprintf(fPath, PATH_MAX + 1, "%s/%s", dirName, realToken);

                FILE *fp = fopen(fPath, "r");
                fscanf(fp, "%d %d", a, b);
                fclose(fp);
}