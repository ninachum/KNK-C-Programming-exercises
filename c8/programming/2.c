/* check whether there's repeated number in input.
 * It shows how many time each digit has repeated. 
 */

#include <stdio.h>

int main(void)
{
	/* this array stores times that each number repeats. */
	int digit_seen[10] = {0};
	int digit, i;
	/* long : 32-bit */
	long n;

	printf("Enter a number: ");
	scanf("%ld", &n);
	
	while (n > 0) {
		/* get a digit */
		digit = n % 10;
		/* increment the times that the digit has repeated. */
		digit_seen[digit]++;
		/* get a next digit */
		n /= 10;
	}

	printf("Digit:        0  1  2  3  4  5  6  7  8  9\n");
	printf("Occurences:   ");

	for (i = 0; i < 10; i++)
		printf("%d  ", digit_seen[i]);
	printf("\n");

	return 0;
}