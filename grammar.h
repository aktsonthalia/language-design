/* 

Group: 45

Members:

V. Aravindan 		: 		2017B4A70849P
Ankit Sonthalia 	:		2017B4A70468P
Rohit K Bharadwaj   :		2017B4A70633P
Ritik Bavdekar      :     	2017B4A70349P

*/
#include "linkedlist.h"

#ifndef structures_h
#define structures_h
#include "structures.h"
#endif


struct linkedList* getRight(struct rule* r);
struct rule** getRules(struct grammar* g);
struct rule* createRule(char* line);
void readGrammar(char* filename, struct grammar** G);
void printRule(struct rule* r);
void printGrammar(struct grammar* g);
