/* 

Group: 45

Members:

V. Aravindan 		: 		2017B4A70849P
Ankit Sonthalia 	:		2017B4A70468P
Rohit K Bharadwaj   :		2017B4A70633P
Ritik Bavdekar      :     	2017B4A70349P

*/
#include "typeinfo.h"
#include "grammar.h"
#include "linkedlist.h"

#ifndef structures_h
#define structures_h
#include "structures.h"
#endif

parseTree* createEmptyParseTree();

parseTreeNode* createNode(char* symbol,tokenStreamNode* t);

void createChildren (parseTreeNode* n, int i,grammar* g);

void deleteChildren(parseTreeNode* n);

void printParsePrettyUtil(parseTreeNode* n,int space);

void printParseTreePretty(parseTree* tree);

void printParseTree(parseTree* tree);
void printParseUtil(parseTreeNode* root);

void printParseTreeNode(parseTreeNode* n);
parseTreeNode* PreOrderSuccessor(parseTree* tree,parseTreeNode* node);
void PreOrderSuccessorUtil(parseTreeNode* node,int *flag,parseTreeNode** next);

parseTreeNode* createDummyNode(char* symbol);