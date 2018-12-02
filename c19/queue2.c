#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

struct node {
	int data;
	struct node *next;
};

struct node *first = NULL;
struct node *last = NULL;

void terminate(const char *message)
{
	printf("%s\n", message);
	exit(EXIT_FAILURE);
}

void insert(int i)
{
	struct node *new_node = malloc(sizeof(struct node));
	if (new_node == NULL)
		terminate("Malloc for new_node failed.\n");
	new_node->data = i;
	new_node->next = NULL;

	if (is_empty())
		first = new_node;
	else
		last->next = new_node;
	last = new_node;
}

void remove(void)
{
	struct node *old_node = first;
	first = first->next;
	free(old_node);	
}

int first_item(void)
{
	if (is_empty())
		terminate("There's no item.\n");
	return first->data;
}

int last_item(void)
{
	if (is_empty())
		terminate("There's no item.\n");
	return last->data;
}

bool is_empty(void)
{
	return first == NULL;
}