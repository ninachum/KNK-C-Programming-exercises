#include "queueADT.h"
#include <stdio.h>


int main(void)
{
	Queue q1, q2;

	q1 = create();
	q2 = create();

	insert(q1, 1);
	printf("stored 1 in q1.\n");
	insert(q1, 2);
	printf("stored 2 in q1.\n");
	insert(q1, 3);
	printf("stored 3 in q1.\n");
	insert(q1, 4);
	printf("stored 4 in q1.\n");
	insert(q1, 5);
	printf("stored 5 in q1.\n");

	insert(q2, first_item(q1));
	printf("stored 1 in q2.\n");
	my_remove(q1);
	insert(q2, first_item(q1));
	printf("stored 2 in q2.\n");
	my_remove(q1);
	insert(q2, first_item(q1));
	printf("stored 3 in q2.\n");
	my_remove(q1);
	insert(q2, first_item(q1));
	printf("stored 4 in q2.\n");
	my_remove(q1);
	insert(q2, first_item(q1));
	printf("stored 5 in q2.\n");
	my_remove(q1);

	printf("last item in q2 is : %d\n", last_item(q2));

	destroy(q2);
	destroy(q1);

	return 0;
}