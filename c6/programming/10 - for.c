#include <stdio.h>

int main(void)
{
	int month, day, year,
		e_month, e_day, e_year;

	printf("Enter a date(mm/dd/yy): ");
	scanf("%d / %d / %d", &month, &day, &year);
	e_month = month;
	e_day = day;
	e_year = year;

	if(month > 0 && day > 0 && year > 0) {
		for(;;) {
			printf("Enter a date(mm/dd/yy): ");
			scanf("%d / %d / %d", &month, &day, &year);
			if(month == 0 && day == 0 && year == 0)
				break;
			if(year < e_year) {
				e_year = year;
				e_month = month;
				e_day = day;
			}
			else if(year == e_year) {
				if(month < e_month) {
				e_year = year;
				e_month = month;
				e_day = day;
				}
				else if(month == e_month) {
					if(day < e_day) {
					e_year = year;
					e_month = month;
					e_day = day;
					}
				}
			}
		}
	}

	printf("%.2d/%.2d/%.2d is the earliest date.\n", e_month, e_day, e_year);

	return 0;
}

				


