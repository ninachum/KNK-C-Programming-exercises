#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define abs(x) ((x) >= 0 ? (x) : (-(x)))

void print_result(int closest_dept_hour, int closest_dept_minute,
				  int closest_arrival_hour, int closest_arrival_minute);

int main(void)
{
	FILE *fp;
	int curr_dept_hour, curr_dept_minute, curr_arrival_hour, curr_arrival_minute, curr_convert;
	int closest_dept_hour, closest_dept_minute, closest_arrival_hour, closest_arrival_minute, closest_convert;
	int user_hour, user_minute, user_convert;
	int temp;
	bool is_first = true, recently_changed;

	if ((fp = fopen("flights.dat", "r")) == NULL) {
		printf("error : can't open flights.dat \n");
		exit(EXIT_FAILURE);
	}
	printf("input depature time (hh:mm , 24-hour) : ");
	scanf("%d : %d", &user_hour, &user_minute);
	user_convert = user_hour * 60 + user_minute;

	while ((temp = fscanf(fp, "%d : %d  %d : %d",
		&curr_dept_hour, &curr_dept_minute, &curr_arrival_hour, &curr_arrival_minute))
		== 4) {
		if (is_first) {
			closest_dept_hour = curr_dept_hour, closest_dept_minute = curr_dept_minute;
			closest_arrival_hour = curr_arrival_hour, closest_arrival_minute = curr_arrival_minute;
			closest_convert = curr_dept_hour * 60 + curr_dept_minute;
			recently_changed = true;
			is_first = false;
			continue;
		}

		/* stop comparing time if we've found closest time. (assuming sorted flight schedule) */
		if (recently_changed) {
			curr_convert = curr_dept_hour * 60 + curr_dept_minute;
			if (abs(closest_convert - user_convert) > abs(curr_convert - user_convert)) {
				closest_dept_hour = curr_dept_hour, closest_dept_minute = curr_dept_minute;
				closest_arrival_hour = curr_arrival_hour, closest_arrival_minute = curr_arrival_minute;
				closest_convert = curr_convert;
			}
			else
				recently_changed = false;
		}
		else
			break;
	}

	/* temp is EOF if scanning is done without error. */
	if (1 <= temp && temp <= 3) {
		printf("error : incomplete file \n");
		exit(EXIT_FAILURE);
	}

	if (ferror(fp)) {
		printf("Read Error \n");
		exit(EXIT_FAILURE);
	}

	print_result(closest_dept_hour, closest_dept_minute,
			     closest_arrival_hour, closest_arrival_minute);

	return 0;
}


void print_result(int closest_dept_hour, int closest_dept_minute,
				  int closest_arrival_hour, int closest_arrival_minute)
{
	printf("Closest depature time is %.2d:%.2d AM, ", closest_dept_hour, closest_dept_minute);
	printf("Closest arrival time is %.2d:%.2d PM", closest_arrival_hour, closest_arrival_minute);
}





