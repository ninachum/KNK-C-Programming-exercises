#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

#define QUEUE_SIZE 5
#define PUBLIC /* empty */
#define PRIVATE static
#define EMPTY 0

PRIVATE void terminate(const char *message);

PRIVATE int queue[QUEUE_SIZE];
PRIVATE int insert_idx = 0;
PRIVATE int remove_idx = 0;
PRIVATE int num_items = 0;

PRIVATE void terminate(const char *message)
{
	printf("%s\n", message);
	exit(EXIT_FAILURE);
}

PUBLIC void insert(int i)
{
	if (num_items < QUEUE_SIZE) {
		queue[insert_idx++] = i;
		if (insert_idx >= QUEUE_SIZE)
			insert_idx = 0;
		num_items++;
	}
	else 
		terminate("Failed to insert : queue is full.\n");
	
}

PUBLIC void my_remove(void)
{
	if (!is_empty()) {
		queue[remove_idx++] = EMPTY;
		if (remove_idx >= QUEUE_SIZE)
			remove_idx = 0;
		num_items--;
	}
	else
		terminate("Failed to remove : queue is empty.\n");
}

PUBLIC int first_item(void)
{
	if (is_empty()) {
		terminate("Failed to get a first item in queue : queue is empty.\n");
		return -1;
	}
	return queue[remove_idx];
}

PUBLIC int last_item(void)
{
	if (!is_empty()) {
		if (insert_idx == 0)
			return queue[QUEUE_SIZE - 1];
		else
			return queue[insert_idx - 1];
	}
	else {
		terminate("Failed to get a last item in queue : queue is empty.\n");
		return -1;
	}
}

PUBLIC bool is_empty(void)
{
	return num_items == 0;
}