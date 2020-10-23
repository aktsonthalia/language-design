#include "grammar.h"
#include "linkedlist.h"
#include "utils.h"

typedef struct stackNode stackNode;

typedef struct stack stack;

stack* createStack();

stackNode* createStackNode(char* str);

void push(stack* s, stackNode* n);

stackNode* pop(stack* s);

void printStackNode(stackNode* node);

void printStack(stack* s);

stackNode* ruleReplace(stack* s, struct grammar* g, int i, int* count);

void undoRuleReplace(stack* s, stackNode* n, int count);


