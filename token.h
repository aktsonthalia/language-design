#include "utils.h"

typedef struct
{
	char* lexeme;
	char* symbol;
}token;

void identify_token(char* lexeme, int* index);

int numtokens = 29;

token tokens[29] = { { "<op_or>", "|||"},
                    { "<op_and>", "&&&"},
                    { "<op_mul>", "*"},
                    { "<op_div>", "/"},
                    { "<op_plus>", "+"},
                    { "<op_minus>", "-"},
                    { "<op_equal>", "="},
                    { "<par_open>" ,"("},
                    { "<par_close>", ")"},
                    { "<curl_open>" ,"{"},
                    { "<curl_close>", "}"},
                    { "<sq_open>" ,"["},
                    { "<sq_close>", "]"},
                    { "<colon>", ":"},
                    { "<semicolon>", ";"},
                    { "<k_program>" ,"program"},
                    { "<k_integer>" ,"integer"},
                    { "<k_boolean>" ,"boolean"},
                    { "<k_real>" ,"real"},
                    { "<k_declare>" ,"declare"},
                    { "<k_variables>", "variables"},
                    { "<k_list>", "list"},
                    { "<k_of>", "of"},
                    { "<k_jagged>", "jagged"},
                    { "<k_size>", "size"},
                    { "<k_array>", "array"},
                    { "<k_values>", "values"},
                    { "<var_name>", " "},
                    { "<const>", " "} } ;