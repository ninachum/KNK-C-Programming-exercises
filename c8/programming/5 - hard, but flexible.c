/* prints a table of compound interest */

#include <stdio.h>

#define NUM_RATES (( (int) sizeof(value) / sizeof(value[0])))
#define INITIAL_BALANCE 100.00

int main(void)
{
	int i, low_rate, num_months, month;
	double value[5];

	printf("Enter interest rate (X percent?): ");
	scanf("%d", &low_rate);
	printf("Enter number of months: ");
	scanf("%d", &num_months);

	/* first row example: "Years     6%     7%     8%     9%     10%" */
	printf("\nYears");
	for (i = 0; i < NUM_RATES; i++) {
		printf("%6d%%", low_rate + i);
		value[i] = INITIAL_BALANCE;
	}
	printf("\n");

	/* from second row, new line is printed at annual intervals.
	 * interest will be compounded monthly.
	 */ 
	for (month = 1; month <= num_months; month++) {
		/* calculate interest monthly */
		for (i = 0; i < NUM_RATES; i++)
			/* 12.0 must be 12.0. not 12. */
			value[i] += (low_rate + i) / 12.0 / 100 * value[i];
		/* print at annual intervals; example: "  1    103.43 106.12 108.34 110.36 113.94" */
		if (month % 12 == 0) {
			printf("%3d   ", month / 12);
			for (i = 0; i < NUM_RATES; i++)
				printf("%7.2f", value[i]);
			printf("\n");
		}
	}

	return 0;
}