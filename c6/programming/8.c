/* program that prints a one-month calendar */

#include <stdio.h>

int main(void)
{
	int num_day, start_day, i, stack = 0, print_day;

	printf("Enter number of days in month: ");
	scanf("%d", &num_day);
	printf("Enter starting day of the week (1=Sun, 7=Sat): ");
	scanf("%d", &start_day);

	/* prints initial spaces for starting day of the week */
	for(i = 1; i < start_day; i++) {
		printf("   "); // three spaces for each day (two for two-digits, one for gap between days)
		stack++;
	}

	/* displays the rest of calendar,
	 * printing a new-line character if all 7 days of a week have been already printed
	 */
	for(i = 1; i <= num_day; i++) {
		if(stack == 7) {
			printf("\n");
			stack = 0;
		}
		print_day = i;
		printf("%2d ", print_day);
		stack++;
	}

	return 0;
}	
