/* 

Group: 45

Members:

V. Aravindan 		: 		2017B4A70849P
Ankit Sonthalia 	:		2017B4A70468P
Rohit K Bharadwaj   :		2017B4A70633P
Ritik Bavdekar      :     	2017B4A70349P

*/
#include "grammar.h"
#include "linkedlist.h"
#include "utils.h"

#ifndef structures_h
#define structures_h
#include "structures.h"
#endif

stack* createStack();

stackNode* createStackNode(char* str);

void push(stack* s, stackNode* n);

stackNode* pop(stack* s);

void printStackNode(stackNode* node);

void printStack(stack* s);

stackNode* ruleReplace(stack* s, struct grammar* g, int i, int* count);

void undoRuleReplace(stack* s, stackNode* n, int count);
