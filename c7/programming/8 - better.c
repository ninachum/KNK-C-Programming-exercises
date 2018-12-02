/*
24�ð� �������� �ð��� ���� ��, �̿� ��� �ð��� ���� �����(�̹� ������ ������ �������)
�������� ���/���� �ð��� ����ϴ� ���α׷�
*/

#include <stdio.h>
#include <ctype.h>

int main(void)
{
	int user_hour, user_minute, user_convert, flight_convert, depature_time,  
		arrival_time, time_gap1, time_gap2, depature_hour, depature_minute,
		arrival_hour, arrival_minute;
	char ch;



	/* ����(é��7) : 12�ð� �������� �ð��� �Է¹޵��� �Ͽ���. */
	printf("Enter a 12-hour time[xx:xx AM or PM]: "); 
	/* ���� : scanf�� ���� XX:XX AM(�Ǵ� PM) ������ �ѹ��� �޴� ������ ������.
	 * ���� : ch�� getchar()�� ���� ���� �޾ƿ�. (github���� ���� ��������.)
	 */
	scanf("%2d : %2d %c", &user_hour, &user_minute, &ch);

	/* ����(é��7) : 12�ð� �������� �Է¹��� XX:XX AM (or PM) ������ ������ ��ȯ�ϴ� �ݺ���.
	 * XX:XX ���� �� ���ڿ��� A(or a) �Ǵ� P(or p)�� ã�� AM/PM ����.
	 * ���� : �� ������ ���� for�� ����.
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

	flight_convert = 8 * 60; // ù ��° �������� ��� �ð��� ������ ��ȯ�Ѵ�.
	depature_time = 8 * 60; // ù ��° �������� ��� �ð����� ����� �ʱ�ȭ�Ѵ�.
	arrival_time = 10 * 60 + 16; // ù ��° �������� ���� �ð����� ����� �ʱ�ȭ�Ѵ�.
	time_gap1 = user_convert - flight_convert; // ����ڰ� �Է��� �ð��� ù ��° �������� ��� �ð��� ���̸� ���Ѵ�.
	if(time_gap1 < 0)
		time_gap1 *= -1; // �������, -1�� ���Ͽ� ����� �����.

	flight_convert = 9 * 60 + 43; // �� ��° �������� ��� �ð��� ������ ��ȯ�Ѵ�.
	time_gap2 = user_convert - flight_convert; // ����ڰ� �Է��� �ð��� �� ��° �������� ��� �ð��� ���̸� ���Ѵ�.
	if(time_gap2 < 0)
		time_gap2 *= -1; // �������, -1�� ���Ͽ� ����� �����.
	if(time_gap1 > time_gap2) // ���ݱ����� �ּҰ��� time_gap1��, ������ time_gap2�� ���Ѵ�.
	{
		depature_time = 9 * 60 + 43; // �� ������ �����Ѵٸ�, �������� ��� �ð��� ���� �ð��� �˸°� �缳���Ѵ�.
		arrival_time = 11 * 60 + 52;
		time_gap1 = time_gap2; // time_gap1�� time_gap2�� �����Ѵ�. (�񱳸� ���� �����ϱ� ����)
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

	/* ������ depature_time�� arrival_time(��� ������ ��ȯ�Ǿ�����)�� 12-�ð� �������� ��ȯ �� ���Ŀ� �°� ��� */
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