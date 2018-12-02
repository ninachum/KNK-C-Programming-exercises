/* Tests whether a number is prime */

#include <stdio.h>

#define TRUE 1
#define FALSE 0

int is_prime(int n)
{
	int divisor;

	if (n <= 1)
		return FALSE;
	
	for (divisor = 2; divisor * divisor <= n; divisor++)
		if (n % divisor == 0)
			return FALSE;

	return TRUE;
}

int main(void)
{
	int n;

	printf("Enter a number: ");
	scanf("%d", &n);

	if (is_prime(n))
		printf("prime\n");
	else
		printf("not prime\n");

	return 0;
}