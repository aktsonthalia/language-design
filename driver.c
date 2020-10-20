#include "utils.h"
#include "grammar.h"

int main()
{
	char file[] = "grammar.txt";
	struct grammar* g;
	readGrammar(file, &g);
	printGrammar(g);
}