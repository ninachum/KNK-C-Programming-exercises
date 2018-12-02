#include <stdio.h>

int main(void)
{
	int input_1, input_2;
	
	printf("Enter a number: ");
	scanf("%d", &input_1);

	printf("The reversal is: ");

	for(;;) {
		input_2 = input_1 % 10;
		printf("%d", input_2);
		input_1 /= 10;

		if(input_1 == 0)
			break;
	}

	printf("\n");

	return 0;
}
