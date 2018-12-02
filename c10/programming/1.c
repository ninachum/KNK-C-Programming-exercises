/* a program that asks the user to enter a series of parentheses and/or braces.
 * then, it indicates whether or not they're properly nested.
 */

#include <stdbool.h> /* C99 only */
#include <stdio.h>
#include <stdlib.h>

#define STACK_SIZE 100

/* external variables */
unsigned char contents[STACK_SIZE];
int top = 0;

/* prototypes */
void make_empty(void);
bool is_empty(void);
bool is_full(void);
void push(unsigned char i);
unsigned char pop(void);
void stack_underflow(void);
void stack_overflow(void);

void take_and_process_input(void);

int main(void)
{
	make_empty();
	take_and_process_input();

	if (is_empty() == false)
		printf("Parentheses/braces are not nested properly.\n");
	else
		printf("Parentheses/braces are nested properly.\n");

	return 0;
}


/* stack operations */
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

void push(unsigned char i)
{
	if(is_full())
		stack_overflow();
	else
		contents[top++] = i;
}

unsigned char pop(void)
{
	if (is_empty())
		stack_underflow();
	else
		return contents[--top];
}

void stack_overflow(void)
{
	printf("Parentheses/braces are not nested properly.\n");
	exit(0);
}

void stack_underflow(void)
{
	printf("Parentheses/braces are not nested properly.\n");
	exit(0);
}
/* end of stack operations */


void take_and_process_input(void)
{
	unsigned char ch, last;
	int i = 0;

	printf("Enter parentheses and/or braces: ");

	while ( (ch = getchar()) != '\n' && is_full() == false ) {

		if (ch == '{' || ch == '(')
			push(ch);

		else if (ch == '}' || ch == ')') {
			last = pop();
			if ((last == '(' && ch == ')') || (last == '{' && ch == '}'))
				continue;
			else {
				printf("Parentheses/braces are not nested properly.\n");
				exit(0);
			}
		}
		else {
			printf("Undefined character.\n");
			exit(0);
		}
	}


}
