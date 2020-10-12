struct linked_list;

extern struct linked_list* createEmptyList();

extern void insert(struct linked_list* list, char* data, int len);

extern void display(struct linked_list* list);

