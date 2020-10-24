#include "stack.h"
#include "utils.h"

typedef struct stackNode 
{
	char* symbol;
	bool isTerminal;
	struct stackNode* next;
}stackNode;

typedef struct stack 
{
	stackNode* top;
	int count;
}stack;

char* getStackNodeSymb(stackNode s) {
	return s.symbol;
}
void setStackNodeSymb(stackNode s, char* sym) {
	 s.symbol = sym;
}

bool getStackNodeIsTerm(stackNode s) {
	return s.isTerminal;
}

void setStackNodeIsTerm(stackNode s, bool t) {
	s.isTerminal = t;
}

stackNode* getStackNodeNext(stackNode s) {
	return s.next;
}

void setStackNodeNext(stackNode s, stackNode* sn) {
	s.next = sn;
}

stackNode* getStackTop(stack s) {
	return s.top;
}
void setStackTop(stack s, stackNode* top) {
	s.top = top;
}

int getStackCount(stack s) {
	return s.count;
}

void setStackCount(stack s, int cnt) {
	s.count = cnt;
}

stack* createStack()
{
	stack* newStack = (stack*) malloc(sizeof(stack));
	newStack->top = NULL;
	newStack->count = 0;
	return newStack;
}

stackNode* createStackNode(char* str)
{
	stackNode* newnode = (stackNode*) malloc (sizeof(stackNode));
	
	newnode->symbol = str;
	newnode->isTerminal = !(str[0] == '<');
	newnode->next = NULL;

	return newnode;
}

void push(stack* s, stackNode* n)
{
	n->next = s->top;
	s->top = n;
	s->count++;
}

stackNode* pop(stack* s)
{
	if(s->count == 0)
		return NULL;

	stackNode* temp = s->top;
	s->top = temp->next;
	s->count--;

	return temp;
}

void printStackNode(stackNode* node)
{
	printf("symbol: %s, isTerminal: %d \n", node->symbol, (int)node->isTerminal);
}

void printStack(stack* s)
{
	stackNode* temp = s->top;
	int count = 0;
	while(temp)
	{
		printf("stack element #%d:\n", count++);
		printStackNode(temp);
		temp = temp->next;
		printf("\n");
	}
}

stackNode* ruleReplace(stack* s, struct grammar* g, int i, int* count)
{
	stackNode* top = pop(s);

	node* temp = getHead(getRight((getRules(g))[i]));
	stack* buffer = createStack();

	while(temp)
	{
		stackNode* newnode = createStackNode(getData(temp));
		push(buffer, newnode);
		temp = getNext(temp);
		(*count)++;
	}

	stackNode* curr = pop(buffer);

	while(curr)
	{
		push(s, curr);
		curr = pop(buffer);
	}

	return top;
}

void undoRuleReplace(stack* s, stackNode* n, int count)
{
	for(int i=0; i<count; i++)
		pop(s);
	push(s, n);
}