/* Sums a series of square */

#include <stdio.h>

int main(void)
{
	double n, sum = 0;

	printf("This program sums a series of integers. \n");
	printf("Enter integers (0 to terminate): ");
	
		scanf("%lf", &n); // To initialize n.
	while(n != 0)
	{
		sum += n;
		scanf("%lf", &n);
	}

	printf("The sum is: %f\n", sum); // %lf can be used, too (C99)

	return 0;
}