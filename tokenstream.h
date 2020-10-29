/* 

Group: 45

Members:

V. Aravindan 		: 		2017B4A70849P
Ankit Sonthalia 	:		2017B4A70468P
Rohit K Bharadwaj   :		2017B4A70633P
Ritik Bavdekar      :     	2017B4A70349P

*/
#include "utils.h"
#include "token.h"

#ifndef structures_h
#define structures_h
#include "structures.h"
#endif

tokenStream* createEmptyTokenStream();
tokenStreamNode* createTokenStreamNode(token_idx i, char* lexeme, int line_number);
void addToken(tokenStream* t, tokenStreamNode* node);
void printToken(tokenStreamNode* node);
void printTokenStream(tokenStream* t);

