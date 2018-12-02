#include <stdio.h>

struct date {
	int month, day, year;
};

int compare_dates(struct date d1, struct date d2);

int main(void)
{
	struct date date_1, date_2;
	int result;

	printf("Enter date 1(mm/dd/yy form) :");
	scanf("%2d / %2d / %4d", &date_1.month, &date_1.day, &date_1.year);
	printf("Enter date 2(mm/dd/yy form) :");
	scanf("%2d / %2d / %4d", &date_2.month, &date_2.day, &date_2.year);

	result = compare_dates(date_1, date_2);

	if (result == -1)
		printf("date_1 is earlier.\n");
	else if (result == 1)
		printf("date_2 is earlier.\n");
	else if (result == 0)
		printf("same date.\n");

	return 0;

}

int compare_dates(struct date d1, struct date d2)
{
	if (d1.year < d2.year)
		return -1;
	else if (d1.year > d2.year)
		return 1;
	else
		if (d1.month < d2.month)
			return -1;
		else if (d1.month > d2.month)
			return 1;
		else
			if (d1.day < d2.day)
				return -1;
			else if (d1.day > d2.day)
				return 1;
			else
				return 0;
}

