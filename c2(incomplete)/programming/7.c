#include <stdio.h>

int main(void)
{
	int total, dollar_20, dollar_10, dollar_5, dollar_1;

	printf("Enter a dollar amount: ");
	scanf("%d", &total);

	dollar_20 = total / 20;
	total %= 20;
	printf("$20 bills: %d\n", dollar_20);

	dollar_10 = total / 10;
	total %= 10;
	printf("$10 bills: %d\n", dollar_10);

	dollar_5 = total / 5;
	total %= 5;
	printf(" $5 bills: %d\n", dollar_5);

	dollar_1 = total;
	printf(" $1 bills: %d\n", dollar_1);

	return 0;
}