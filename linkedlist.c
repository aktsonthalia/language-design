#include "utils.h"
#include "linkedlist.h"

typedef struct node
{
	char* data;
	struct node* next;
} node;

typedef struct linkedList
{
	struct node* head;
} linkedList;


struct node* getHead(linkedList* l)
{
	return l->head;
}

struct node* getNext(node* n)
{
	return n->next;	
}

char* getData(node* n)
{
	return n->data;
}



struct linkedList* createEmptyList()
{
	struct linkedList* list;
	list = (struct linkedList*)malloc(sizeof(struct linkedList));
	list->head = NULL;

	return list;
}

void insert(struct linkedList* list, char* data)
{
	struct node* new_node = (struct node*)malloc(sizeof(node));
	new_node->data = (char*)malloc((strlen(data)+1) * sizeof(char));
	strcpy(new_node->data, data);

	if(!list->head)
		list->head = new_node;

	else
	{
		struct node* temp = list->head;

		while(temp->next)
			temp = temp->next;

		temp->next = new_node;
	}
}

void printList(struct linkedList* list)
{
	struct node* temp = list->head;

	while(temp)
	{
		printf("%s ", temp->data);
		temp = temp->next;
	}

	// printf("\n");
}
