#include <ctype.h>
#include <string.h>
#include "token.h"
typedef enum token{jagged, array, integer,real,boolean, size, variables, values,declare,list,of,COLON,SQOP,SQCP, PoP , PcL , BoP , BcL , SEMICOLON ,PLUS,MINUS,DIVIDE,MULTIPLY,OR,AND,EQUAL,static_constant,var} token;

token identify_token(char* lexeme)
{
       char str1[] = "jagged";
       char str2[] = "array";
       char str3[] = "integer";
       char str4[] = "real";
       char str5[] = "boolean";
       char str6[] = "size";
       char str7[] = "variables";
       char str8[] = "values";
       char str9[] = "declare";
       char str10[] = "list";
       char str11[] = "of";
       char str12[] = ":";
       char str13[] = "[";
       char str14[] = "]";
       char str15[] = "(";
       char str16[] = ")";
       char str17[] = "{";
       char str18[] = "}";
       char str19[] = ";";
       char str20[] = "+";
       char str21[] = "-";
       char str22[] = "/";
       char str23[] = "*";
       char str24[] = "|||";
       char str25[] = "&&&";
       char str26[] = "=";
 
       if ( strcmp(lexeme, str1) == 0 ) {
               return jagged;
       } else if ( strcmp(lexeme, str2) == 0 ) {
               return array;
       } else if ( strcmp(lexeme, str3) == 0 ) {
               return integer;
       } else if ( strcmp(lexeme, str4) == 0 ) {
               return real;
       } else if ( strcmp(lexeme, str5) == 0 ) {
               return boolean;
       } else if ( strcmp(lexeme, str6) == 0 ) {
               return size;
       } else if ( strcmp(lexeme, str7) == 0 ) {
               return variables;
       } else if ( strcmp(lexeme, str8) == 0 ) {
               return values;
       } else if ( strcmp(lexeme, str9) == 0 ) {
               return declare;
       } else if (strcmp(lexeme, str10) == 0) {
               return list;
       } else if (strcmp(lexeme, str11) == 0) {
               return of;
       } else if (strcmp(lexeme, str12) == 0) {
               return COLON;
       } else if (strcmp(lexeme, str13) == 0) {
               return SQOP;
       } else if (strcmp(lexeme, str14) == 0) {
               return SQCP;
       } else if (strcmp(lexeme, str15) == 0) {
               return PoP;
       } else if (strcmp(lexeme, str16) == 0) {
               return PcL;
       } else if (strcmp(lexeme, str17) == 0) {
               return BoP;
       } else if (strcmp(lexeme, str18) == 0) {
               return BcL;
       } else if (strcmp(lexeme, str19) == 0) {
               return SEMICOLON;
       } else if (strcmp(lexeme, str20) == 0) {
               return PLUS;
       } else if (strcmp(lexeme, str21) == 0) {
               return MINUS;
       } else if (strcmp(lexeme, str22) == 0) {
               return DIVIDE;
       } else if (strcmp(lexeme, str23) == 0) {
               return MULTIPLY;
       } else if (strcmp(lexeme, str24) == 0) {
               return OR;
       } else if (strcmp(lexeme, str25) == 0) {
               return AND;
       } else if (strcmp(lexeme, str26) == 0) {
               return EQUAL;
       }
 
       char firstDig = lexeme[0];
 
       if (isdigit(firstDig)) {
               return static_constant;
       } else {
               return var;
       }
 
}
