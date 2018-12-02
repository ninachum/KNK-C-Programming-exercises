#include <stdio.h>

int main(void)
{
	float knot;

	printf("wind speed(in knots)?: ");
	scanf("%f", &knot);

	if(knot < 1)
		printf("Calm\n");
	else if(knot < 4)
		printf("Light air\n");
	else if(knot < 28)
		printf("Breeze\n");
	else if(knot < 48)
		printf("Gale\n");
	else if(knot < 64)
		printf("Storm\n");
	else
		printf("Hurricane\n");

	return 0;
}