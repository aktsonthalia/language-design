#include "utils.h"
#include "parsetree.h"

parseTree* createEmptyParseTree()
{
	parseTree* t = (parseTree*)malloc(sizeof(parseTree));
	t->root = NULL;
	return t;
}

parseTreeNode* createNode(char* symbol)
{
	parseTreeNode* temp = (parseTreeNode* )malloc(sizeof(parseTreeNode));
	temp->symbol = symbol;
	temp->children=NULL;
	temp->num_children=0;
	temp->type=NULL;
	temp->depth = 0;
	return temp;
}

void createChildren (parseTreeNode* n, int i,grammar* g)
{
	rule* r=getRules(g)[i];
	linkedList* ll=getRight(r);
	node* temp = ll->head;
	while(temp)
	{
		// parseTreeNode* child=createNode(temp->data);
		n->num_children++;
		temp = temp->next;
	}
	temp = ll->head;
	n->children=(parseTreeNode**)malloc(sizeof(parseTreeNode*) * (n->num_children));
	int index=0;
	while(temp)
	{
		parseTreeNode* child=createNode(temp->data);
		n->children[index]=child;
		temp=temp->next;
		index++;
	}
	return ;
}

void deletechildren(parseTreeNode* n)
{
	if(n==NULL) return;
	// n->children=NULL;
	// n->num_children=0;
	for(int i=0;i<(n->num_children);i++)
	{
		parseTreeNode* child= n->children[i];
		deletechildren(child);
		free(child);
	}
	return;
}


void printParseUtil(parseTreeNode* n,int space)
{
	if(n==NULL) return;
	for(int i=0;i<space;i++)
	{
		printf(" ");
	}
	printf("%s \n",n->symbol);

	for(int i=0;i<n->num_children;i++)
	{
		printParseUtil(n->children[i],space+4);
	}
	return ;
}


void printParseTree(parseTreeNode* n)
{
	printParseUtil(n,0);
	return ;
}

void printParseTreeNode(parseTreeNode* n)
{
	printf("%s\t", n->symbol);
// type expression
	
	if(n->tag == terminal)
	{
		printf("%s\t", n->lexeme);
		printf("%d\t", n->line_number);
	}

	else
	{
		printf("%d\t", n->rule);
	}

	printf("%d\n", n->depth);
}


