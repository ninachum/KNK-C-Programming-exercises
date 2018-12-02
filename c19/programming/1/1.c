/* a program that asks the user to enter a series of parentheses and/or braces.
 * then, it indicates whether or not they're properly nested.
 */

#include <stdbool.h> /* C99 only */
#include <stdio.h>
#include <stdlib.h>
#include "stackADT3.h"

/* prototypes */
void take_and_process_input(void);


int main(void)
{
	take_and_process_input();

	return 0;
}


void take_and_process_input(void)
{
	Stack s;
	unsigned char ch, last;
	int i = 0;

	s = create();

	printf("Enter parentheses and/or braces: ");

	while ( (ch = getchar()) != '\n' && is_full(s) == false ) {

		if (ch == '{' || ch == '(')
			push(s, ch);

		else if (ch == '}' || ch == ')') {
			last = pop(s);
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

	if (is_empty(s) == false)
		printf("Parentheses/braces are not nested properly.\n");
	else
		printf("Parentheses/braces are nested properly.\n");

	destroy(s);
}
