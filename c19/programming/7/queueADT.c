#include <stdio.h>
#include <stdlib.h>
#include "queueADT.h"

#define PRIVATE static
#define PUBLIC /* empty */

struct node {
	int data;
	struct node *next;
};

struct queue_type {
	struct node *first;
	struct node *last;
};

PRIVATE void terminate(const char *message)
{
	printf("%s\n", message);
	exit(EXIT_FAILURE);
}

Queue create(void)
{
	Queue q = malloc(sizeof(struct queue_type));
	if (q == NULL)
		terminate("Error in create: stack could not be created.");
	q->first = NULL;
	q->last = NULL;
	return q;
}

void destroy(Queue q)
{
	while (!is_empty(q))
		my_remove(q);
	free(q);
}

PUBLIC void insert(Queue q, Item i)
{
	struct node *new_node = malloc(sizeof(struct node));
	if (new_node == NULL)
		terminate("Malloc for new_node failed.\n");
	new_node->data = i;
	new_node->next = NULL;

	if (is_empty(q))
		q->first = new_node;
	else
		q->last->next = new_node;
	q->last = new_node;
}

PUBLIC void my_remove(Queue q)
{
	struct node *old_node;

	if (!is_empty(q)) {
		old_node = q->first;
		q->first = q->first->next;
		free(old_node);
	}
	else
		terminate("Failed to remove : queue is empty.\n");
}

PUBLIC int first_item(Queue q)
{
	if (is_empty(q))
		terminate("Failed to get first item : queue is empty.\n");
	return q->first->data;
}

PUBLIC int last_item(Queue q)
{
	if (is_empty(q))
		terminate("Failed to get last item : queue is empty.\n");
	return q->last->data;
}

PUBLIC bool is_empty(Queue q)
{
	return q->first == NULL;
}