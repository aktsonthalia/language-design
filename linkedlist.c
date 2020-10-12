#include "commonlibs.h"

typedef struct node
{
	char* data;
	struct node* next;
} node;

typedef struct linked_list
{
	struct node* head;
} linked_list;

struct linked_list* createEmptyList()
{
	struct linked_list* list;
	list = (struct linked_list*)malloc(sizeof(struct linked_list));
	list->head = NULL;

	return list;
}

void insert(struct linked_list* list, char* data)
{
	struct node* new_node = (struct node*)malloc(sizeof(node));
	new_node->data = (char*)malloc(sizeof(data));
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

void display(struct linked_list* list)
{
	struct node* temp = list->head;

	while(temp)
	{
		printf("%s\n", temp->data);
		temp = temp->next;
	}
}
