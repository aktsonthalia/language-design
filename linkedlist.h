typedef struct node node;
typedef struct linkedList linkedList;

struct node* getHead(linkedList* l);
char* getData(node* n);
struct node* getNext(node* n);

struct linkedList* createEmptyList();

void insert(struct linkedList* list, char* data);

void printList(struct linkedList* list);

