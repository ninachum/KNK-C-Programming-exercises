/*
24시간 형식으로 시간을 받은 뒤, 이와 출발 시간이 가장 가까운(이미 지나간 비행기라도 상관없음)
비행편의 출발/도착 시간을 출력하는 프로그램
*/

#include <stdio.h>
#include <ctype.h>

int main(void)
{
	int user_hour, user_minute, user_convert, flight_convert, depature_time,  
		arrival_time, time_gap1, time_gap2, depature_hour, depature_minute,
		arrival_hour, arrival_minute;
	char ch;



	/* 변경(챕터7) : 12시간 형식으로 시간을 입력받도록 하였음. */
	printf("Enter a 12-hour time[xx:xx AM or PM]: "); 
	/* 개선 : scanf를 통해 XX:XX AM(또는 PM) 형식을 한번에 받는 것으로 수정함.
	 * 기존 : ch는 getchar()를 통해 따로 받아옴. (github에서 보고 따라했음.)
	 */
	scanf("%2d : %2d %c", &user_hour, &user_minute, &ch);

	/* 변경(챕터7) : 12시간 형식으로 입력받은 XX:XX AM (or PM) 형식을 분으로 변환하는 반복문.
	 * XX:XX 직후 두 글자에서 A(or a) 또는 P(or p)를 찾아 AM/PM 결정.
	 * 개선 : 위 개선에 따른 for문 제거.
	 */

	if(toupper(ch) == 'A') {
		if(user_hour == 12) 
			user_hour = 0;
		user_convert = user_hour * 60 + user_minute;
	}
	else if(toupper(ch) == 'P') {
		if(user_hour == 12)
			user_hour = 0;
		user_convert = user_hour * 60 + user_minute + 60 * 12;
	}

	flight_convert = 8 * 60; // 첫 번째 비행편의 출발 시간을 분으로 변환한다.
	depature_time = 8 * 60; // 첫 번째 비행편의 출발 시간으로 결과를 초기화한다.
	arrival_time = 10 * 60 + 16; // 첫 번째 비행편의 도착 시간으로 결과를 초기화한다.
	time_gap1 = user_convert - flight_convert; // 사용자가 입력한 시간과 첫 번째 비행편의 출발 시간의 차이를 구한다.
	if(time_gap1 < 0)
		time_gap1 *= -1; // 음수라면, -1을 곱하여 양수로 만든다.

	flight_convert = 9 * 60 + 43; // 두 번째 비행편의 출발 시간을 분으로 변환한다.
	time_gap2 = user_convert - flight_convert; // 사용자가 입력한 시간과 두 번째 비행편의 출발 시간의 차이를 구한다.
	if(time_gap2 < 0)
		time_gap2 *= -1; // 음수라면, -1을 곱하여 양수로 만든다.
	if(time_gap1 > time_gap2) // 지금까지의 최소값인 time_gap1과, 현재의 time_gap2를 비교한다.
	{
		depature_time = 9 * 60 + 43; // 비교 조건을 만족한다면, 비행편의 출발 시간과 도착 시간을 알맞게 재설정한다.
		arrival_time = 11 * 60 + 52;
		time_gap1 = time_gap2; // time_gap1에 time_gap2를 저장한다. (비교를 마저 진행하기 위함)
	}

	flight_convert = 11 * 60 + 19;
	time_gap2 = user_convert - flight_convert;
	if(time_gap2 < 0)
		time_gap2 *= -1;
	if(time_gap1 > time_gap2)
	{
		depature_time = 11 * 60 + 19;
		arrival_time = 13 * 60 + 31;
		time_gap1 = time_gap2;
	}

	flight_convert = 12 * 60 + 47;
	time_gap2 = user_convert - flight_convert;
	if(time_gap2 < 0)
		time_gap2 *= -1;
	if(time_gap1 > time_gap2)
	{
		depature_time = 12 * 60 + 47;
		arrival_time = 15 * 60;
		time_gap1 = time_gap2;
	}

	flight_convert = 14 * 60;
	time_gap2 = user_convert - flight_convert;
	if(time_gap2 < 0)
		time_gap2 *= -1;
	if(time_gap1 > time_gap2)
	{
		depature_time = 14 * 60;
		arrival_time = 16 * 60 + 8;
		time_gap1 = time_gap2;
	}
	
	flight_convert = 15 * 60 + 45;
	time_gap2 = user_convert - flight_convert;
	if(time_gap2 < 0)
		time_gap2 *= -1;
	if(time_gap1 > time_gap2)
	{
		depature_time = 15 * 60 + 45;
		arrival_time = 17 * 60 + 55;
		time_gap1 = time_gap2;
	}

	flight_convert = 19 * 60;
	time_gap2 = user_convert - flight_convert;
	if(time_gap2 < 0)
		time_gap2 *= -1;
	if(time_gap1 > time_gap2)
	{
		depature_time = 19 * 60;
		arrival_time = 21 * 60 + 20;
		time_gap1 = time_gap2;
	}

	flight_convert = 21 * 60 + 45;
	time_gap2 = user_convert - flight_convert;
	if(time_gap2 < 0)
		time_gap2 *= -1;
	if(time_gap1 > time_gap2)
	{
		depature_time = 21 * 60 + 45;
		arrival_time = 23 * 60 + 58;
		time_gap1 = time_gap2;
	}

	/* 결정된 depature_time과 arrival_time(모두 분으로 변환되어있음)을 12-시간 형식으로 변환 및 서식에 맞게 출력 */
	depature_hour = depature_time / 60;
	depature_minute = depature_time % 60;
	
	if(depature_hour < 12) // for AM
	{
		if(depature_hour == 0) // special case, 0:00 AM is...
			depature_hour = 12; // 12:00 AM.
		printf("Closest depature time is %.2d:%.2d AM", depature_hour, depature_minute); // print "hour:minute AM"
	
	}
	else // for PM
	{
		if(depature_hour > 12) // except 12:00 PM (12:00), all PM hours must be subtracted 12. 
			depature_hour -= 12;
		printf("Closest depature time is %.2d:%.2d PM", depature_hour, depature_minute);
	}

	arrival_hour = arrival_time / 60;
	arrival_minute = arrival_time % 60;
	
	if(arrival_hour < 12) // for AM
	{
		if(arrival_hour == 0) // special case, 0:00 AM is...
			arrival_hour = 12; // 12:00 AM.
		printf(", arriving at %.2d:%.2d AM\n", arrival_hour, arrival_minute);
	}
	else // for PM
	{
		if(arrival_hour > 12) // except 12:00 PM (12:00), all PM hours must be subtracted 12. 
			arrival_hour -= 12;
		printf(", arriving at %.2d:%.2d PM\n", arrival_hour, arrival_minute);
	}

	return 0;
}