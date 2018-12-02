/*
24시간 형식으로 시간을 받은 뒤, 이와 출발 시간이 가장 가까운(이미 지나간 비행기라도 상관없음)
비행편의 출발/도착 시간을 출력하는 프로그램
*/

#include <stdio.h>

/* for abs() function */
#include <stdlib.h>

int main(void)
{
	int user_hour, user_minute, user_convert; /* 사용자에게 시간을 입력받고, 이를 분으로 변환하기 위한 변수 */
	int depature_time, arrival_time; /* 각각 가장 가까운 비행편의 출발시간, 그리고 그 비행편의 도착시간을 나타냄 */
	int time_gap1, time_gap2; /* 두 비행편의 현재 시간과의 차이를 비교하기 위함 */
	int depature_hour, depature_minute, arrival_hour, arrival_minute; /* 출력을 위한 시간 변환에 사용됨. depature_time과 arrival_time을 변환한 값일 뿐임 */
	int i; /* 반복을 위한 값 */

	/* 8개 비행편의 출발시간과 도착시간을 나타낸 배열 */
	int depature_arr[8] = { 8 * 60, 9 * 60 + 43, 11 * 60 + 19, 12 * 60 + 47, 14 * 60, 15 * 60 + 45, 19 * 60, 21 * 60 + 45 };
	int arrival_arr[8] = { 10 * 60 + 16, 11 * 60 + 52, 13 * 60 + 31, 15 * 60, 16 * 60 + 8, 17 * 60 + 55, 21 * 60 + 20, 23 * 60 + 58 };

	printf("Enter a 24-hour time[xx:xx]: "); // 24시간 형식으로 시간을 입력받는다.
	scanf("%2d : %2d", &user_hour, &user_minute);

	user_convert = user_hour * 60 + user_minute; // 24시간 형식을 분으로 변환한다.

	/* 첫 번째 비행편의 값으로 가장 가까운 비행편의 출발시간, 그리고 그 비행편의 도착시간을 초기화함. */
	depature_time = depature_arr[0];
	arrival_time = arrival_arr[0];

	/* 동시에, 첫 번째 비행편의 출발 시간과 현재의 시간차이를 첫 번째 비교값으로 초기화함 */
	time_gap1 = abs(depature_arr[0] - user_convert);

	/* 다음 비행편과 지금까지 최단 시간차 비행편(출발시간 기준)의 비교 시작
	 * 데이터가 첫 번째 비행편으로 초기화되었으므로 비교는 ( 8 - 1 )번 이루어진다.
     */
	for (i = 1; i < 8; i++) {

		/* 다음 비행편의 출발 시간과 현재 시간과의 차이를 계산하여 저장 */
		time_gap2 = abs(depature_arr[i] - user_convert);

		/* 지금까지의 최단 시간차가 다음 비행편의 시간차보다 크다면, 최단 시간차를 수정 */
		if (time_gap1 > time_gap2) {
			time_gap1 = time_gap2;

			/* 최단 시간차인 출발시간과, 그에 따른 도착 시간을 수정함. */
			depature_time = depature_arr[i];
			arrival_time = arrival_arr[i];
		}
	}

	/* 결정된 depature_time과 arrival_time(모두 분으로 변환되어있음)을 12-시간 형식으로 변환 및 서식에 맞게 출력 */
	depature_hour = depature_time / 60;
	depature_minute = depature_time % 60;

	if (depature_hour < 12) // for AM
	{
		if (depature_hour == 0) // special case, 0:00 AM is...
			depature_hour = 12; // 12:00 AM.
		printf("Closest depature time is %.2d:%.2d AM", depature_hour, depature_minute); // print "hour:minute AM"

	}
	else // for PM
	{
		if (depature_hour > 12) // except 12:00 PM (12:00), all PM hours must be subtracted 12. 
			depature_hour -= 12;
		printf("Closest depature time is %.2d:%.2d PM", depature_hour, depature_minute);
	}

	arrival_hour = arrival_time / 60;
	arrival_minute = arrival_time % 60;

	if (arrival_hour < 12) // for AM
	{
		if (arrival_hour == 0) // special case, 0:00 AM is...
			arrival_hour = 12; // 12:00 AM.
		printf(", arriving at %.2d:%.2d AM\n", arrival_hour, arrival_minute);
	}
	else // for PM
	{
		if (arrival_hour > 12) // except 12:00 PM (12:00), all PM hours must be subtracted 12. 
			arrival_hour -= 12;
		printf(", arriving at %.2d:%.2d PM\n", arrival_hour, arrival_minute);
	}

	return 0;
}