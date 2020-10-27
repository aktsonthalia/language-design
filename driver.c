#include "utils.h"
#include "lexer.h"
#include "stack.h"
#include "grammar.h"
#include "linkedlist.h"
#include "parsetree.h"
#include "typeinfo.h"
#include "parser.h"

int main()
{
	createCache();
	printf("main");
	struct grammar* g;
	char grammar_file[] = "grammar.txt";
	readGrammar(grammar_file, &g);
	// printGrammar(g);

	cleanWhiteSpaces("testcases/t4.txt");
	tokenStream* s = createEmptyTokenStream();
	char source_file[] = "processed.txt";
	tokeniseSourcecode(source_file, s);
	// printf("main\n");
	// printTokenStream(s);

	parseTree* tree = createEmptyParseTree();

	createParseTree(tree, s, g);

}