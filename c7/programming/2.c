/* prints a table of squares using a while statement */

#include <stdio.h>

int main(void)
{
	int i, n, counter = 0;

	printf("This program prints a table of squares. \n");
	printf("Enter number of entries in table: ");
	scanf("%d", &n);
	getchar(); // to delete \n (pressing enter key during last scanf() call) in buffer.

	for(i = 1; i <= n; i++) {
		printf("%10d%10d\n", i, i * i);
		counter++;
		if (counter == 24) {
			printf("Press Enter to continue...");
			while(getchar() != 10) // if input is not \n (enter key), program won't continue.
				;
			counter = 0;
		}
	}


	return 0;
}