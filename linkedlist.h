struct node;
struct linked_list;

extern struct linked_list* createEmptyList();

extern void insert(struct linked_list* list, char* data);

extern void printList(struct linked_list* list);

