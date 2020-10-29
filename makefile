default:
	gcc driver.c grammar.c linkedlist.c tokenstream.c lexer.c parsetree.c utils.c token.c parser.c stack.c typeexpressiontable.c -o exec && ./exec

compile : 
	gcc driver.c grammar.c linkedlist.c tokenstream.c lexer.c parsetree.c utils.c token.c parser.c stack.c typeexpressiontable.c -o exec

run : 
	./exec

compile-and-run :
	make compile && make run