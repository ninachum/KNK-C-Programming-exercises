#include <stdio.h>

int main(void)
{
	int input_1, input_2;
	
	printf("Enter a number: ");
	scanf("%d", &input_1);

	printf("The reversal is: ");
	/* use do statement, because when input == 0, at least a excution is needed. */
	do {
		input_2 = input_1 % 10;
		printf("%d", input_2);
		input_1 /= 10;
	} while (input_1 > 0);
	printf("\n");

	return 0;
}
