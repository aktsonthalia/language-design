#include "typeinfo.h"
#include "grammar.h"
#include "linkedlist.h"

#ifndef structures_h
#define structures_h
#include "structures.h"
#endif

parseTree* createEmptyParseTree();

parseTreeNode* createNode(char* symbol);

void createChildren (parseTreeNode* n, int i,grammar* g);

void deletechildren(parseTreeNode* n);

void printParseUtil(parseTreeNode* n,int space);

void printParseTree(parseTreeNode* n);

void printParseTreeNode(parseTreeNode* n);
