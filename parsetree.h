typedef struct parseTreeNode;
typedef struct parseTree;

typedef enum {terminal, non_terminal} Tag;

char* getParseTreeNodeSymb(parseTreeNode p);
int getParseTreeNodeNumChild(parseTreeNode p);
parseTreeNode** getParseTreeNodeChildren(parseTreeNode p);
Tag getParseTreeNodeTag(parseTreeNode p);
char* getParseTreeNodeLexeme(parseTreeNode p);
int getParseTreeNodeLine(parseTreeNode p);
typeinfo* getParseTreeNodeTypeInfo(parseTreeNode p);
int getParseTreeNodeDepth(parseTreeNode p);
int getParseTreeNodeRule(parseTreeNode p);
parseTreeNode* getParseTreeRoot(parseTree p);
void setParseTreeNodeSymb(parseTreeNode p, char* symbol);
void setParseTreeNodeNumChild(parseTreeNode p, int nc);
void setParseTreeNodeChildren(parseTreeNode p, parseTreeNode** c);
void setParseTreeNodeTag(parseTreeNode p, Tag t);
void setParseTreeNodeLexeme(parseTreeNode p, char* l);
void setParseTreeNodeLine(parseTreeNode p, int ln);
void setParseTreeNodeTypeInfo(parseTreeNode p, typeinfo* t);
void setParseTreeNodeDepth(parseTreeNode p, int d);
void setParseTreeNodeRule(parseTreeNode p, int r);
void setParseTreeRoot(parseTree p, parseTreeNode* root);

parseTreeNode* createNode(char* symbol);

void createChildren (parseTreeNode* n, int i,grammar* g);

void deletechildren(parseTreeNode* n);

void printParseUtil(parseTreeNode* n,int space);

void printParseTree(parseTreeNode* n);

void printParseTreeNode(parseTreeNode* n);
