#include <stdio.h>

int main(void)
{
	float amount, i_rate, m_pay;
	int times, i = 1;

	printf("Enter the number of payment: ");
	scanf("%d", &times);
	printf("Enter amount of loan: ");
	scanf("%f", &amount);
	printf("Enter interest rate (ex. 6.0) : ");
	scanf("%f", &i_rate);
	printf("Enter monthly payment: ");
	scanf("%f", &m_pay);
	

	while (times > 0) {
		
		amount -= m_pay;
		amount += amount * i_rate / 100 / 12;
		
		printf("Balance remaining after %d payments: $%.2f\n", i, amount);
		i++;
		times--;
	}

	return 0;
}

