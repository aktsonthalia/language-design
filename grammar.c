#include "utils.h"
#include "linkedlist.h"

char delimiter[2] = " ";

typedef struct rule
{
	char* left;
	struct linkedList* right;
} rule;

typedef struct grammar
{
	struct rule** rules;
	int size;
} grammar;

struct rule* createRule(char* line)
{
	struct rule* new_rule = (struct rule*)malloc(sizeof(struct rule));

	char* token = strtok(line, delimiter);
	new_rule->left = (char*)malloc((strlen(token)+1) * sizeof(char));
	strcpy(new_rule->left, token);

	token = strtok(NULL, delimiter);

	new_rule->right = createEmptyList();

	while(token)
	{
		insert(new_rule->right, token);
		token = strtok(NULL, delimiter);
	}

	return new_rule;
}

void readGrammar(char* filename, struct grammar** G)
{
	struct grammar* g = (struct grammar*)malloc(sizeof(struct grammar));

	int n = countLines(filename);
	g->size = n;

	g->rules = (struct rule**)malloc(n * sizeof(struct rule*));

	FILE* fp = fopen(filename, "r");
	char* line = NULL;
	size_t len = 0;

	for(int i=0; i<n; i++)
	{
		getline(&line, &len, fp);

		//removing newline character
		line[strlen(line)-1] = '\0';
		g->rules[i] = createRule(line);
	}

	*G = g;
	fclose(fp);
}

void printRule(struct rule* r)
{
	printf("%s ---> ", r->left);
	printList(r->right);
}

void printGrammar(struct grammar* g)
{
	for(int i=0; i<g->size; i++)
	{
		printRule(g->rules[i]);
		printf("\n");
	}
}
