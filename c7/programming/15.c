/* Calculates factorial */

#include <stdio.h>

int main(void)
{
	int n, i;
	long double fac = 1;

	printf("Enter a positive integer: ");
	scanf("%d", &n);

	for(i = 1; i <= n; i++)
		fac *= i;

	printf("Factorial of %d: %Lf\n", n, fac);

	return 0;
}

/* when fac is short type(16 bit in this system), maximum(not causing overflow) n is 7.
 * when fac is int type(32 bit in this system), maximum(not causing overflow) n is 12.
 * when fac is long type(32 bit in this system), maximum(not causing overflow) n is 12.
 * when fac is long long type(64 bit in this system), maximum(not causing overflow) n is 20.
 * when fac is float type(32 bit in this system), maximum(not causing overflow) n is 34.
 * when fac is double type(64 bit in this system), maximum(not causing overflow) n is 170.
 * when fac is long double type(64 bit in this system), maximum(not causing overflow) n is 170.
 */
