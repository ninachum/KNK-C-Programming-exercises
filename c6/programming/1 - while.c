#include <stdio.h>

int main(void)
{
	float num=1.00f, largest=0.00f;

	printf("To exit, enter negative number or zero\n");
	
	while (num > 0) {
		printf("Enter a number: ");
		scanf("%f", &num);
		
		if(num > largest)
			largest = num;
	}

	printf("The largest number entered was %.2f\n", largest);

	return 0;
}

