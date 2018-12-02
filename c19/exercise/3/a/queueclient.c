#include "queue.h"
#include <stdio.h>


int main(void)
{

	insert(1);
	insert(2);
	insert(3);
	insert(4);
	insert(5);
	my_remove();

	printf("first item in queue: %d\n", first_item());
	printf("last item in queue: %d\n", last_item());


	return 0;
}