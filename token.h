#include<stdio.h>

typedef enum {jagged, array, integer,real,boolean, size, variables, values,declare,list,of,COLON,SQOP,SQCP, PoP , PcL , BoP , BcL , SEMICOLON ,PLUS,MINUS,DIVIDE,MULTIPLY,OR,AND,EQUAL,static_constant,var} token;
token identify_token(char* lexeme);