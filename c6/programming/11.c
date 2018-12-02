/* computes and prints mathematical constant e = 1 + 1/1! + 1/2! + 1/3! ... */

#include <stdio.h>

int main(void)
{
	float e = 1.00f, denom = 1.00f;
	int n, i;

	printf("Enter the precision of approximation(positive integer) : ");
	scanf("%d", &n);

	/* if precision == 1, this loop won't be executed. (e = 1)*/
	printf("approximate e : 1");
	for(i = 1; i < n; i++) {
		e += 1/denom; // if denom is integer type, always 0 will be added up.
		printf(" + 1/%d!", i);
		denom *= (i + 1);
	}

	printf("\n = %f\n", e);


	return 0;
}