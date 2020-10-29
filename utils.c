/* 

Group: 45

Members:

V. Aravindan 		: 		2017B4A70849P
Ankit Sonthalia 	:		2017B4A70468P
Rohit K Bharadwaj   :		2017B4A70633P
Ritik Bavdekar      :     	2017B4A70349P

*/
#include "utils.h"

#ifndef structures_h
#define structures_h
#include "structures.h"
#endif

#define MAXCHAR1 1000

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

        if (stat(dirName, &st) == -1) {              
                if(mkdir(dirName, 0755) != -1){            
                char filepath[MAXCHAR1+1];           
                snprintf(filepath, MAXCHAR1 + 1, "%s/%s", dirName, realToken);

                FILE *fp = fopen(filepath, "w");
                fprintf(fp, "%d %d", lineIdx, countToken);
                fclose(fp);
            }else{
                perror("mkdir: ");
            }
        } else {
                char filepath[MAXCHAR1+1];           
                snprintf(filepath, MAXCHAR1 + 1, "%s/%s", dirName, realToken);

                FILE *fp = fopen(filepath, "w");
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



            } 
            else 
            {

                strcpy(oldToken, realToken);
                createFile(realToken, lineIdx, countToken);


            }

        }


    }



    void getNTCache(char* nt, int* a, int* b) 
    {
 // pass reference of integer when calling the function.
        char* realToken;
        realToken = getRealToken(nt);

        char *prefix = "non-terminals";

        snprintf(dirName, NAME_MAX + 1,"%s", prefix);

                char filepath[MAXCHAR1+1];             // file path
                //printf("DirName: %s\n", dirName);
                snprintf(filepath, MAXCHAR1 + 1, "%s/%s", dirName, realToken);

                FILE *fp = fopen(filepath, "r");
                fscanf(fp, "%d %d", a, b);
                fclose(fp);
            }

            void strip(char *text)
            {
              int count1=0,count2=0;

              while(text[count1]!='\0')
              {
                if(text[count1]!=' ' || text[count1] != '\t')
                {
                  text[count2]=text[count1];
                  count2++;
              }
              count1++;
          }
          text[count2]='\0';
          return;
      }

      bool containsNoCharacters(char* str)
      {
        for(int i=0; i<strlen(str); i++)
        {
            // printf("containsNoCharacters %d\n", str[i]);
            if(str[i] != ' ' || str[i] != '\t' || str[i] != '\n' || str[i] != '\0')
                return false;
        }

        return true;

    }

    void cleanWhiteSpaces(char* filename)
    {
        FILE* FILEIN = fopen(filename, "r");
        FILE* FILEOUT=fopen("processed.txt","w");
        char line[MAXCHAR1];

        while (fgets(line,MAXCHAR1,FILEIN))
        {

        // if(!containsCharacters(line))
        //     continue;

        // printf("line\n");
            if(containsNoCharacters(line))
                continue;

            if(line[0] == '\n')
                continue;


            int count1=0;
            int count2=0;
            while(line[count1]==' ' || line[count1]=='\t')
            {
                count1++;
            }

            if(line[count1] == '\0' || line[count1] == '\n')
                continue;

            char buffer[MAXCHAR1];

            while(line[count1+1]!='\0')
            {
                if((line[count1]==' ' && line[count1+1]==' '))
                {
                // count1++;
                // continue;
                }
                else if((line[count1]=='\t'))
                {

                }
                else
                {
                    buffer[count2]=line[count1];
                    count2++;
                }

                count1++;

            }
            buffer[count2]='\0';
            fprintf(FILEOUT, "%s\n",buffer); 

        }
        fclose(FILEIN);
        fclose(FILEOUT);
        return;
    }

    int isTerminal(char* symbol)
    {
        if(symbol[0]=='<') return 0;
        return 1;
    }