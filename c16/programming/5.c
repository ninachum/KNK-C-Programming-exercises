#include <stdio.h>

#define NUM_ENTRY 8
#define abs(x) ((x) > 0 ? (x) : (-(x)))

struct time find_closest_depature(int time_in_minute);
void print_time(struct time s1);

struct time {
	int depature;
	int arrival;
} time_list[NUM_ENTRY] = {
	{8 * 60, 10 * 60 + 16},
	{9 * 60 + 43, 11 * 60 + 52},
	{11 * 60 + 19, 13 * 60 + 31},
	{12 * 60 + 47, 15 * 60},
	{14 * 60, 16 * 60 + 8},
	{15 * 60 + 45, 17 * 60 + 55},
	{19 * 60, 21 * 60 + 20},
	{21 * 60 + 45, 23 * 60 + 58}
};

struct time closest;

int main(void)
{
	int user_hour, user_minute, user_convert;

	printf("Enter a 24-hour time[xx:xx]: ");
	scanf("%2d : %2d", &user_hour, &user_minute);

	user_convert = user_hour * 60 + user_minute;

	closest = find_closest_depature(user_convert);
	
	print_time(closest);

	return 0;
}

struct time find_closest_depature(int time_in_minute)
{
	struct time result;

	int i, time_gap_ori, time_gap_new;

	result.depature = time_list[0].depature;
	result.arrival = time_list[0].arrival;
	time_gap_ori = abs(time_in_minute - result.depature);

	for (i = 1; i < NUM_ENTRY; i++) {
		time_gap_new = abs(time_in_minute - time_list[i].depature);
		if (time_gap_ori > time_gap_new) {
			time_gap_ori = time_gap_new;
			result.depature = time_list[i].depature;
			result.arrival = time_list[i].arrival;
		}
	}

	return result;
}

void print_time(struct time s1)
{
	printf("Closest depature time is: %.2d:%.2d, ", s1.depature / 60, s1.depature % 60);
	printf("arriving %.2d:%.2d\n", s1.arrival / 60, s1.arrival % 60);
}