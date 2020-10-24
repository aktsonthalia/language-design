#include "utils.h"
#include "token.h"

typedef int token_idx;

typedef struct tokenStreamNode tokenStreamNode;

typedef struct tokenStream tokenStream;

tokenStream* createEmptyTokenStream();
tokenStreamNode* createTokenStreamNode(token_idx i, char* lexeme, int line_number);
void addToken(tokenStream* t, tokenStreamNode* node);
void printToken(tokenStreamNode* node);
void printTokenStream(tokenStream* t);

tokenStream* createEmptyTokenStream();
tokenStreamNode* createTokenStreamNode(token_idx i, char* lexeme, int line_number);
void addToken(tokenStream* t, tokenStreamNode* node);
void printToken(tokenStreamNode* node);
void printTokenStream(tokenStream* t);
token_idx getTokenStreamNodeID(tokenStreamNode t);
void setTokenStreamNodeID(tokenStreamNode t, token_idx id);
char* getTokenStreamNodeLexeme(tokenStreamNode t);
void setTokenStreamNodeLexeme(tokenStreamNode t, char* lex );
int getTokenStreamNodeLine(tokenStreamNode t);
void setTokenStreamNodeLine(tokenStreamNode t, int line);
tokenStreamNode* getTokenStreamNodeNext(tokenStreamNode t);
void setTokenStreamNodeNext(tokenStreamNode t, tokenStreamNode* n);
int getTokenStreamCount(tokenStream s);
void setTokenStreamCount(tokenStream s, int c);
tokenStreamNode* getTokenStreamHead(tokenStream s);
void setTokenStreamHead(tokenStream s, tokenStreamNode* h);