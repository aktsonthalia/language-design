#include "grammar.h"
#include "typeinfo.h"

typedef struct parseTreeNode
{
	char* symbol;
	int num_children;
	parseTreeNode** children;
	enum {terminal, non_terminal} tag;
	char* lexeme;
	int line_number;
	typeinfo* type;
	int depth;
	int rule;
}parseTreeNode;

typedef struct parseTree
{
	parseTreeNode* root;
} parseTree;

char* getParseTreeNodeSymb(parseTreeNode p) {
	return p.symbol;
}
void setParseTreeNodeSymb(parseTreeNode p, char* symbol) {
	p.symbol = symbol;
}
int getParseTreeNodeNumChild(parseTreeNode p) {
	return p.num_children;
}
void setParseTreeNodeNumChild(parseTreeNode p, int nc) {
	p.num_children = nc;
}
parseTreeNode** getParseTreeNodeChildren(parseTreeNode p) {
	return p.children;
}
void setParseTreeNodeChildren(parseTreeNode p, parseTreeNode** c) {
	p.children = c;
}
Tag getParseTreeNodeTag(parseTreeNode p) {
	return p.tag;
}
void setParseTreeNodeTag(parseTreeNode p, Tag t) {
	 p.tag = t;
}
char* getParseTreeNodeLexeme(parseTreeNode p) {
	return p.lexeme;
}
void setParseTreeNodeLexeme(parseTreeNode p, char* l) {
	 p.lexeme = l;
}
int getParseTreeNodeLine(parseTreeNode p) {
	return p.line_number;
}
void setParseTreeNodeLine(parseTreeNode p, int ln) {
	 p.line_number = ln;
}
typeinfo* getParseTreeNodeTypeInfo(parseTreeNode p) {
	return p.type;
}
void setParseTreeNodeTypeInfo(parseTreeNode p, typeinfo* t) {
	p.type = t;
}
int getParseTreeNodeDepth(parseTreeNode p) {
	return p.depth;
}
void setParseTreeNodeDepth(parseTreeNode p, int d) {
	 p.depth = d;
}
int getParseTreeNodeRule(parseTreeNode p) {
	return p.rule;
}
void setParseTreeNodeRule(parseTreeNode p, int r) {
	 p.rule = r;
}
typedef struct parseTree
{
	parseTreeNode* root;
} parseTree;

parseTreeNode* getParseTreeRoot(parseTree p) {
	return p.root;
}
void setParseTreeRoot(parseTree p, parseTreeNode* root) {
	p.root = root;
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
	linkedList* ll=r->right;
	node* temp=ll->head;
	while(temp)
	{
		// parseTreeNode* child=createNode(temp->data);
		n->num_children++;
		temp=temp->next;
	}
	temp=ll->head;
	n->children=(parseTreeNode**)malloc(sizeof(parseTreeNode*) * (n->num_children))
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
		printf(' ');
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
	
	char tag[] = (n->tag == terminal) ? "terminal" : "non_terminal";
	printf("%s\t", tag);

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


