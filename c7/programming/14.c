/* Newton's method for computing the square root of a positive floating-point number. */

#include <stdio.h>
#include <math.h>

int main(void)
{
	double x, y = 1, old_y = 0, temp, avg;

	printf("Enter a positive number: ");
	scanf("%lf", &x);

	/* Initialized old_y to enter this loop. That is, initial old_y value is meaningless. */
	while(fabs(old_y - y) >= 0.00001 * y) {
		temp = x / y;
		avg = (y + temp) / 2;
		old_y = y;
		y = avg;
	}

	printf("Square root: %f\n", avg);

	return 0;
}