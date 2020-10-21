#include "utils.h"
#include "token.h"

typedef int token_idx;

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

tokenStream* createEmptyTokenStream();
tokenStreamNode* createTokenStreamNode(token_idx i, char* lexeme, int line_number);
void addToken(tokenStream* t, tokenStreamNode* node);
void printToken(tokenStreamNode* node);
void printTokenStream(tokenStream* t);
