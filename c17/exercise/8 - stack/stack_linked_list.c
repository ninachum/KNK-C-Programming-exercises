#include <stdio.h>
#include "stack_linked_list.h"
#include <stdlib.h>

struct node {
	int number;
	struct node *next;
};

struct node *top = NULL;

void make_empty(void)
{
	struct node *prev, *cur;

	for (prev = top, cur = top->next; prev != NULL; prev = cur, cur = cur->next)
		free(prev);
	free(prev);

	top = NULL;
}

bool is_empty(void)
{
	return top == NULL;
}

bool push(int n)
{
	struct node *new_node;
	new_node = malloc(sizeof(struct node));
	if (new_node == NULL) {
		printf("Error: malloc failed in add_to_list\n");
		return false;
	}
	new_node->number = n;
	new_node->next = top;
	top = new_node;

	return true;
}

int pop(void)
{
	int pop_result;
	struct node *temp;

	if (is_empty())
		stack_underflow();
	else {
		pop_result = top->number;
		temp = top->next;
		free(top);
		top = temp;
		return pop_result;
	}
}


void stack_overflow(void)
{
	printf("stack overflow.\n");
	exit(EXIT_FAILURE);
}
void stack_underflow(void)
{
	printf("stack underflow.\n");
	exit(EXIT_FAILURE);
}

