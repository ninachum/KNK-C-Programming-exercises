/* check whether there's repeated number in input. */

#include <stdio.h>

#define TRUE 1
#define FALSE 0


int main(void)
{
	int digit_seen[10] = {FALSE};
	int digit;
	long n;

	for (;;) {
		printf("Enter a number (0 or below to end): ");
		scanf("%ld", &n);
		
		if (n <= 0)
			break;

		while (n > 0) {
			digit = n % 10;
			if (digit_seen[digit])
				break;
			digit_seen[digit] = TRUE;
			n /= 10;
		}
	
		if (n > 0)
			printf("Repeated digit\n");
		else
			printf("No repeated digit\n");
	}

	printf("terminted\n");

	return 0;
}