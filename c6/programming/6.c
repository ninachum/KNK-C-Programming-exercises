/* prints all even squares between 1 and n */

#include <stdio.h>

int main(void)
{
	int n, i;

	printf("Enter a number: ");
	scanf("%d", &n);

	/* 1 * 1 = 1 is skipped */
	for (i = 2; i * i <= n; i++) {
		if (i * i % 2 == 0)
			printf("%d\n", i * i);
	}

	return 0;
}	