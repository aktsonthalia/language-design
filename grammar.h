struct rule;
struct grammar;
struct rule* createRule(char* line);
struct grammar* createGrammar(char* filename);
void printRule(struct rule* r);
void printGrammar(struct grammar* g);
