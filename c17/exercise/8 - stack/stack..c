#include <stdio.h>
#include "stack.h"
#include <stdlib.h>

int top = 0;
double contents[STACK_SIZE];

void make_empty(void)
{
	top = 0;
}

bool is_empty(void)
{
	return top == 0;
}

bool is_full(void)
{
	return top == STACK_SIZE;
}

void push(double i)
{
	if (is_full())
		stack_overflow();
	else
		contents[top++] = i;
}

double pop(void)
{
	if (is_empty())
		stack_underflow();
	else
		return contents[--top];
}


void stack_overflow(void)
{
	printf("stack overflow.\n");
	exit(0);
}
void stack_underflow(void)
{
	printf("stack underflow.\n");
	exit(0);
}