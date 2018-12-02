#include <stdio.h>

int main(void)
{
	int nume, denom, temp, m, n, gcd;

	printf("Enter a fraction (X/Y): ");
	scanf("%d / %d", &nume, &denom);
	
	/* initialization for calculating GCD */
	m = nume, n = denom;

	/* calculates GCD */
	while (n != 0) {
		temp = m % n;
		m = n;
		n = temp;
	}
	gcd = m;

	printf("In lowest terms: %d/%d\n", nume / gcd, denom / gcd);

	return 0;
}



