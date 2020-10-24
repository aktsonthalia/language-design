#include "utils.h"
#include "lexer.h"
#include "stack.h"
#include "grammar.h"
#include "linkedlist.h"
#include "parsetree.h"
#include "typeinfo.h"


int main()
{

	// linkedList* l = createEmptyList();
	// insert(l, "token1");
	// insert(l, "token1");
	// insert(l, "token1");
	// insert(l, "token1");
	
	// printList(l);
	struct grammar* g;
	char grammar_file[] = "grammar.txt";
	readGrammar(grammar_file, &g);
	printGrammar(g);

	printf("=======================================================\n");
	
	tokenStream* s = createEmptyTokenStream();
	char source_file[] = "source.txt";
	tokeniseSourcecode(source_file, s);
	// printf("main\n");
	printTokenStream(s);

	parseTree* tree = createEmptyParseTree();
}