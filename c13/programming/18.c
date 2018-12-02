#include <stdio.h>
#include <string.h>

#define LENGTH 50

void read_and_print_when(char *msg);

int main(void)
{
	char msg[LENGTH + 1];

	read_and_print_when(msg);

	return 0;
}

void read_and_print_when(char *msg)
{
	int day, month, year;
	char *months[] = { "January", "February", "March", "April",
		"May", "June", "July", "August",
		"September", "October", "November", "December" };

	printf("Enter a date (mm/dd/yyyy): ");
	scanf("%d/%d/%4d", &month, &day, &year);

	printf("You entered the date %s %d, %d\n", months[month - 1], day, year);

}

	
