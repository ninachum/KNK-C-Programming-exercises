#include <stdio.h>

int main(void)
{
	int num;

	printf("Enter a number: ");
	scanf("%d", &num);

	if(0 <= num && num < 10)
		printf("1 digit\n");
	else if(num < 100)
		printf("2 digits\n");
	else if(num < 1000)
		printf("3 digits\n");
	else if(num < 10000)
		printf("4 digits\n");
	else
		printf("what?\n");

	return 0;
}