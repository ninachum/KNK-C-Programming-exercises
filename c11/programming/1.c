#include <stdio.h>

void pay_amount(int dollars, int *twenties, int *tens, int *fives, int *ones);

int main(void)
{
	int total, dollar_20, dollar_10, dollar_5, dollar_1;

	printf("Enter a dollar amount: ");
	scanf("%d", &total);

	pay_amount(total, &dollar_20, &dollar_10, &dollar_5, &dollar_1);

	return 0;
}

void pay_amount(int dollars, int *twenties, int *tens, int *fives, int *ones)
{

	*twenties = dollars / 20;
	dollars %= 20;
	printf("$20 bills: %d\n", *twenties);

	*tens = dollars / 10;
	dollars %= 10;
	printf("$10 bills: %d\n", *tens);

	*fives = dollars / 5;
	dollars %= 5;
	printf(" $5 bills: %d\n", *fives);

	*ones = dollars;
	printf(" $1 bills: %d\n", *ones);

}
