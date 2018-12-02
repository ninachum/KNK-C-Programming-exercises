/* calculates a broker's commission */

#include <stdio.h>

int main(void)
{
	float commission_A, commission_B , share_price, value;
	int share_num;

	printf("Enter the number of shares: ");
	scanf("%d", &share_num);
	printf("Enter price of a share: ");
	scanf("%f", &share_price);

	value = share_num * share_price;

	if(value < 2500.00f)
		commission_A = 30.00f + .017f * value;
	else if(value < 6250.00f)
		commission_A = 56.00f + .0066f * value;
	else if(value < 20000.00f)
		commission_A = 76.00f + .0034f * value;
	else if(value < 50000.00f)
		commission_A = 100.00f + .0022f * value;
	else if(value < 500000.00f)
		commission_A = 155.00f + .0011f * value;
	else
		commission_A = 255.00f + .0009f * value;
	
	if(commission_A < 39.00f)
		commission_A = 39.00f;	
	
	if(share_num < 2000)
		commission_B = 33.00f + 0.03f * share_num;
	else
		commission_B = 33.00f + 0.02f * share_num;

	printf("Commission of a original broker: $%.2f\n", commission_A);
	printf("Commission of a new broker: $%.2f\n", commission_B);

	return 0;
}