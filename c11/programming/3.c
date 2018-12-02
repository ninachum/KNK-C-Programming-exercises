#include <stdio.h>

void reduce(int nume, int denom, int *reduced_nume, int *reduced_denom);

int main(void)
{
	int nume, denom, reduced_nume, reduced_denom;

	printf("Enter a fraction (X/Y): ");
	scanf("%d / %d", &nume, &denom);

	reduce(nume, denom, &reduced_nume, &reduced_denom);

	printf("In lowest terms: %d/%d\n", reduced_nume, reduced_denom);

	return 0;
}

void reduce(int nume, int denom, int *reduced_nume, int *reduced_denom)
{	
	int m = nume, n = denom,
		gcd, temp;

	/* calculates GCD */
	while (n != 0) {
		temp = m % n;
		m = n;
		n = temp;
	}
	gcd = m;

	*reduced_nume = nume / gcd;
	*reduced_denom = denom / gcd;
}
