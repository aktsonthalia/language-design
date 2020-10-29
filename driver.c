/* 

Group: 45

Members:

V. Aravindan 		: 		2017B4A70849P
Ankit Sonthalia 	:		2017B4A70468P
Rohit K Bharadwaj   :		2017B4A70633P
Ritik Bavdekar      :     	2017B4A70349P

*/
#include "utils.h"
#include "lexer.h"
#include "stack.h"
#include "grammar.h"
#include "linkedlist.h"
#include "parsetree.h"
#include "typeinfo.h"
#include "parser.h"
#include "typeexpressiontable.h"

#define MAXLEN 100

void divider();

int main(int argc, char* argv[])
{
	createCache();

	struct grammar* g;
	char grammar_file[] = "grammar.txt";
	readGrammar(grammar_file, &g);

	printf("Please enter the number of the testcase file you want to run. (See the folder 'testcases/'): ");
	int x;
	scanf("%d", &x);
	printf("\n");
	divider();
	char prefix[] = "testcases/t";
	char suffix[] = ".txt";
	char* inputfile = malloc(MAXLEN * sizeof(char));
	sprintf(inputfile, "%s%d%s", prefix, x, suffix); 

	printf("Input file: %s\n", inputfile);
	printf("All subsequent operations will be carried out on this file until the current executable is terminated.\n");
	printf("Please note that this file will be preprocessed to remove stray spaces first and the processed file can be found in 'processed.txt'\n");
	divider();

	cleanWhiteSpaces(inputfile);
	tokenStream* s = createEmptyTokenStream();
	char source_file[] = "processed.txt";
	tokeniseSourcecode(source_file, s);

	parseTree* tree;
	typeExpressionTable* table;

	int choice;
	while(true)
	{
		printf("Choices:\n");
		printf("1 : Create parse tree\n");
		printf("2 : Construct Type Expression table\n");
		printf("3 : Print parse tree\n");
		printf("4 : Print Type Expression Table\n");
		printf("0 : Exit\n");
		printf("\n");

		printf("Enter a number (0-4): ");

		scanf("%d", &choice);
		printf("\n");
		printf("Choice entered: %d\n", choice);
		switch(choice)
		{
			case 0:

			divider();
			printf("Exit command received. Wrapping up...\n");
			divider();
			return 0;

			break;

			case 1:

			divider();
			tree = createEmptyParseTree();
			createParseTree(tree, s, g);
			divider();

			break;

			case 2:

			divider();
			table = createTable();
			populateTable(tree, table);
			divider();

			break;

			case 3:

			divider();
			printf("Printing parse tree...\n");
			divider();
			printParseTree(tree);
			divider();

			break;

			case 4:

			divider();
			printf("Printing Type Expression Table...\n");
			printTypeExpressionTable(*table);
			divider();

			break;

			default:
			
			divider();
			printf("Invalid choice: please try again.\n");
			divider();
			
		}



	}



	printParseTree(tree);
	printTypeExpressionTable(*table);


}

void divider()
{
	printf("\n");

	for(int i=0; i<100; i++)
		printf("*");

	printf("\n");
}