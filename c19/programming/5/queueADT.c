#include <stdio.h>
#include <stdlib.h>
#include "queueADT.h"

#define QUEUE_SIZE 100
#define PUBLIC /* empty */
#define PRIVATE static
#define EMPTY 0

struct queue_type {
	Item queue[QUEUE_SIZE];
	int insert_idx;
	int remove_idx;
	int num_items;
};

PRIVATE void terminate(const char *message);

PRIVATE void terminate(const char *message)
{
	printf("%s\n", message);
	exit(EXIT_FAILURE);
}

Queue create(void)
{
	Queue q = malloc(sizeof(struct queue_type));
	if (q == NULL)
		terminate("Failed to create : memory not available.\n");
	q->insert_idx = 0;
	q->remove_idx = 0;
	q->num_items = 0;

	return q;
}

void destroy(Queue q)
{
	free(q);
}

PUBLIC void insert(Queue q, Item i)
{
	if (q->num_items < QUEUE_SIZE) {
		q->queue[q->insert_idx++] = i;
		if (q->insert_idx >= QUEUE_SIZE)
			q->insert_idx = 0;
		q->num_items++;
	}
	else 
		terminate("Failed to insert : queue is full.\n");
	
}

PUBLIC void my_remove(Queue q)
{
	if (!is_empty(q)) {
		q->queue[q->remove_idx++] = EMPTY;
		if (q->remove_idx >= QUEUE_SIZE)
			q->remove_idx = 0;
		q->num_items--;
	}
	else
		terminate("Failed to remove : queue is empty.\n");
}

PUBLIC Item first_item(Queue q)
{
	if (is_empty(q)) {
		terminate("Failed to get a first item in queue : queue is empty.\n");
		return -1;
	}
	return q->queue[q->remove_idx];
}

PUBLIC Item last_item(Queue q)
{
	if (!is_empty(q)) {
		if (q->insert_idx == 0)
			return q->queue[QUEUE_SIZE - 1];
		else
			return q->queue[q->insert_idx - 1];
	}
	else {
		terminate("Failed to get a last item in queue : queue is empty.\n");
		return -1;
	}
}

PUBLIC bool is_empty(Queue q)
{
	return q->num_items == 0;
}