struct rule;
struct grammar;
struct rule* createRule(char* line);
void readGrammar(char* filename, struct grammar** G);
void printRule(struct rule* r);
void printGrammar(struct grammar* g);
