#include "utils.h"
#include "tokenstream.h"

typedef struct tokenStreamNode{
	token_idx id;
	char* lexeme;
	int line_number;
	struct tokenStreamNode* next;
}tokenStreamNode;

typedef struct tokenStream{
	int count;
	tokenStreamNode* head;
}tokenStream;


token_idx getTokenStreamNodeID(tokenStreamNode t) {
	return t.id;
}
char* getTokenStreamNodeLexeme(tokenStreamNode t) {
	return t.lexeme;
}
int getTokenStreamNodeLine(tokenStreamNode t) {
	return t.line_number;
}
tokenStreamNode* getTokenStreamNodeNext(tokenStreamNode t) {
	return t.next;
}
void setTokenStreamNodeID(tokenStreamNode t, token_idx id) {
	t.id = id;
}
void setTokenStreamNodeLexeme(tokenStreamNode t, char* lex ) {
	t.lexeme = lex;
}
void setTokenStreamNodeLine(tokenStreamNode t, int line) {
	t.line_number = line;
}
void setTokenStreamNodeNext(tokenStreamNode t, tokenStreamNode* n) {
	t.next = n;
}
int getTokenStreamCount(tokenStream s) {
	return s.count;
}
void setTokenStreamCount(tokenStream s, int c) {
	s.count = c;
}
tokenStreamNode* getTokenStreamHead(tokenStream s) {
	return s.head;
}
void setTokenStreamHead(tokenStream s, tokenStreamNode* h) {
	s.head = h;
}

tokenStream* createEmptyTokenStream()
{
	tokenStream* s= (tokenStream*) malloc(sizeof(tokenStream));
	s->head=NULL;
	s->count=0;
	return s;
}


tokenStreamNode* createTokenStreamNode(token_idx i, char* lexeme, int line_number)
{
	tokenStreamNode* t = (tokenStreamNode*) malloc(sizeof(tokenStreamNode));

	t->id = i;
	t->lexeme = (char*)malloc(strlen(lexeme) * sizeof(char));
	strcpy(t->lexeme, lexeme);
	t->line_number = line_number;
	t->next = NULL;

	return t;
}

void addToken(tokenStream* t, tokenStreamNode* node)
{
	if(t->count==0)
	{
		t->head = node;
		t->count++;
		return;
	}
	// printToken(node);

	tokenStreamNode* temp = t->head;

	while(temp->next)
	{
		temp=temp->next;
	}

	temp->next = node;
	t->count++;
}

void printToken(tokenStreamNode* node)
{
	printf("Lexeme: %s, Token id: %d, Line number: %d\n", node->lexeme, node->id, node->line_number);
}

void printTokenStream(tokenStream* t)
{
	tokenStreamNode* temp = t->head;
	// int n = 0;
	while(temp)
	{
		// n++;
		// printf("printtokenstream %d\n", n);
		printToken(temp);
		temp = temp->next;
	}
}

