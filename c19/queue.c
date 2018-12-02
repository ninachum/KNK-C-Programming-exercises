#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

#define QUEUE_SIZE 100

int queue[QUEUE_SIZE];
int insert_idx = 0;
int remove_idx = 0;
int num_items = 0;

void terminate(const char *message)
{
	printf("%s\n", message);
	exit(EXIT_FAILURE);
}

void insert(int i)
{
	queue[insert_idx++] = i;
	if (insert_idx >= QUEUE_SIZE)
		insert_idx = 0;
	num_items++;
}

void remove(void)
{
	queue[remove_idx++] = 0;
	if (remove_idx >= QUEUE_SIZE)
		remove_idx = 0;
	num_items--;
}

int first_item(void)
{
	if (is_empty())
		terminate("There's no item.\n");
	return queue[remove_idx];
}

int last_item(void)
{
	if (is_empty())
		terminate("There's no item.\n");
	
	if (insert_idx == 0)
		return queue[QUEUE_SIZE - 1];
	else
		return queue[insert_idx - 1];
}

bool is_empty(void)
{
	return num_items == 0;
}