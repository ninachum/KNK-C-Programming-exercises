#include <stdio.h>
#include "stackADT3.h"

int main(void)
{
	Stack s1, s2;
	char *result1;
	s1 = create();
	s2 = create();

	push(s1, "nano");
	push(s1, "boost");

	result1 = pop(s1);
	printf("Popped \"%s\" from s1\n", result1);
	push(s2, result1);
	result1 = pop(s1);
	printf("Popped \"%s\" from s1\n", result1);
	push(s2, result1);

	

	destroy(s1);

	while (!is_empty(s2))
		printf("Popped \"%s\" from s2\n", (char *)pop(s2));

	push(s2, "activated");
	make_empty(s2);
	if (is_empty(s2))
		printf("s2 is empty\n");
	else
		printf("s2 is not empty\n");

	destroy(s2);

	return 0;
}