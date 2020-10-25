#include "utils.h"

typedef struct rule
{
	char* left;
	struct linkedList* right;
} rule;

typedef struct grammar
{
	struct rule** rules;
	int size;
} grammar;

typedef struct node
{
	char* data;
	struct node* next;
} node;

typedef struct linkedList
{
	struct node* head;
} linkedList;

typedef struct typeInfo
{
	char* varname;
	enum {primitive, rect_array, jagged_array} tag;
	enum {not_applicable, static_, dynamic} init;  

	// union 
	// {
	// //populate later
	// }typeExp;

}typeInfo;

typedef enum {terminal, non_terminal} Tag;
typedef struct parseTreeNode
{
	char* symbol;
	int num_children;
	struct parseTreeNode** children;
	Tag tag;
	char* lexeme;
	int line_number;
	typeInfo* type;
	int depth;
	int rule;
}parseTreeNode;

typedef struct parseTree
{
	parseTreeNode* root;
} parseTree;


typedef struct stackNode 
{
	char* symbol;
	bool isTerminal;
	struct stackNode* next;
}stackNode;

typedef struct stack 
{
	stackNode* top;
	int count;
}stack;

typedef int token_idx;

typedef struct tokenStreamNode{
	token_idx id;
	char* lexeme;
	int line_number;
	struct tokenStreamNode* next;
}tokenStreamNode;

typedef struct tokenStream{
	int count;
	tokenStreamNode* head;
}tokenStream;

