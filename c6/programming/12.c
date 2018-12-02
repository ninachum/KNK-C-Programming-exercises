/* computes and prints mathematical constant e.
 * add terms until the current term (1/n!) becomes less than epsilon.
 */

#include <stdio.h>

int main(void)
{
	float e = 1.00f, denom = 1.00f, epsilon;
	int i;

	printf("Enter the epsilon(real number, between 1 and 0) : ");
	scanf("%f", &epsilon);

	printf("approximate e : 1");
	for(i = 1; 1 / denom >= epsilon; i++) {
		e += 1/denom; // if denom is integer type, always 0 will be added up.
		printf(" + 1/%d!", i);
		denom *= (i + 1);
	}
	
	printf("\n = %f\n", e);

	return 0;
}