#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

#define PRIVATE static
#define PUBLIC /* empty */

struct node {
	int data;
	struct node *next;
};

PRIVATE struct node *first = NULL;
PRIVATE struct node *last = NULL;

PRIVATE void terminate(const char *message)
{
	printf("%s\n", message);
	exit(EXIT_FAILURE);
}

PUBLIC void insert(int i)
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

PUBLIC void my_remove(void)
{
	if (!is_empty()) {
		struct node *old_node = first;
		first = first->next;
		free(old_node);
	}
	else
		terminate("Failed to remove : queue is empty.\n");
}

PUBLIC int first_item(void)
{
	if (is_empty())
		terminate("Failed to get first item : queue is empty.\n");
	return first->data;
}

PUBLIC int last_item(void)
{
	if (is_empty())
		terminate("Failed to get last item : queue is empty.\n");
	return last->data;
}

PUBLIC bool is_empty(void)
{
	return first == NULL;
}