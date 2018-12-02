#include <stdio.h>

void print_result(int month, int day, int year);

int main(int argc, char *argv[])
{
	int month, day, year;

	if (sscanf(argv[1], "%d-%d-%d", &month, &day, &year) == 3)
		print_result(month, day, year);
	else if (sscanf(argv[2], "%d/%d/%d", &month, &day, &year) == 3)
		print_result(month, day, year);
	else
		printf("format is either month-day-year or month/day/year.\n");

	return 0;
}

void print_result(int month, int day, int year)
{
	switch (month) {
	case 1: printf("January"); break;
	case 2: printf("February"); break;
	case 3: printf("March"); break;
	case 4: printf("April"); break;
	case 5: printf("May"); break;
	case 6: printf("June"); break;
	case 7: printf("July"); break;
	case 8: printf("August"); break;
	case 9: printf("September"); break;
	case 10: printf("October"); break;
	case 11: printf("November"); break;
	case 12: printf("December"); break;
	default: printf("None"); break;
	}
	printf(" %d,", day);
	printf(" %d", year);
}




