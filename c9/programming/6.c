#include <stdio.h>

double calc_polynomial(double x);
double power(double x, double n);

int main(void)
{
	double n;

	printf("Enter a number of x: ");
	scanf("%lf", &n);

	printf("Result is : %.2f", calc_polynomial(n));

	return 0;
}

double calc_polynomial(double x)
{
	return 3 * power(x, 5) + 2 * power(x, 4) - 5 * power(x, 3) - power(x, 2) + 7 * x - 6;
}

double power(double x, double n)
{
	if (n == 0)
		return 1;
	else
		return x * power(x, n - 1);
}
