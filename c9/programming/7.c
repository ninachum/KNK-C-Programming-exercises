#include <stdio.h>

int calc_power(int x, int n);

int main(void)
{
	int x, n;

	printf("Enter x and n: ");
	scanf("%d %d", &x, &n);

	printf("Power is: %d", calc_power(x, n));

	return 0;
}

int calc_power(int x, int n)
{
	int temp;

	if (n == 0)
		return 1;

	if (n % 2 == 0) {
		temp = calc_power(x, n / 2);
		return temp * temp;
	}
	else
		return x * calc_power(x, n - 1);
}