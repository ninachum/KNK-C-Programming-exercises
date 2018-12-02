/* check whether there's repeated number in input.
 * It shows which digits were repeated.
 */

#include <stdio.h>

int main(void)
{
	/* this array stores times that each number repeats. */
	int digit_seen[10] = {0};
	int digit, is_repeated = 0;
	/* long : 32-bit */
	long n;

	printf("Enter a number: ");
	scanf("%ld", &n);
	
	printf("Repeated number(s) : ");

	while (n > 0) {
		/* get a digit */
		digit = n % 10;
		/* print if the digit is repeated, but only the first time. */
		if (digit_seen[digit] == 1) {
			printf("%d ", digit);
			/* for not-repeating case. */
			is_repeated++;
		}
		/* increment the times that the digit has repeated. */
		digit_seen[digit]++;
		/* get a next digit */
		n /= 10;
	}

	/* if there's no repeated number... */
	if (is_repeated == 0)
		printf("None\n");

	return 0;
}