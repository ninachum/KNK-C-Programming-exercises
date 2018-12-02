/*
24�ð� �������� �ð��� ���� ��, �̿� ��� �ð��� ���� �����(�̹� ������ ������ �������)
�������� ���/���� �ð��� ����ϴ� ���α׷�
*/

#include <stdio.h>

/* for abs() function */
#include <stdlib.h>

int main(void)
{
	int user_hour, user_minute, user_convert; /* ����ڿ��� �ð��� �Է¹ް�, �̸� ������ ��ȯ�ϱ� ���� ���� */
	int depature_time, arrival_time; /* ���� ���� ����� �������� ��߽ð�, �׸��� �� �������� �����ð��� ��Ÿ�� */
	int time_gap1, time_gap2; /* �� �������� ���� �ð����� ���̸� ���ϱ� ���� */
	int depature_hour, depature_minute, arrival_hour, arrival_minute; /* ����� ���� �ð� ��ȯ�� ����. depature_time�� arrival_time�� ��ȯ�� ���� ���� */
	int i; /* �ݺ��� ���� �� */

	/* 8�� �������� ��߽ð��� �����ð��� ��Ÿ�� �迭 */
	int depature_arr[8] = { 8 * 60, 9 * 60 + 43, 11 * 60 + 19, 12 * 60 + 47, 14 * 60, 15 * 60 + 45, 19 * 60, 21 * 60 + 45 };
	int arrival_arr[8] = { 10 * 60 + 16, 11 * 60 + 52, 13 * 60 + 31, 15 * 60, 16 * 60 + 8, 17 * 60 + 55, 21 * 60 + 20, 23 * 60 + 58 };

	printf("Enter a 24-hour time[xx:xx]: "); // 24�ð� �������� �ð��� �Է¹޴´�.
	scanf("%2d : %2d", &user_hour, &user_minute);

	user_convert = user_hour * 60 + user_minute; // 24�ð� ������ ������ ��ȯ�Ѵ�.

	/* ù ��° �������� ������ ���� ����� �������� ��߽ð�, �׸��� �� �������� �����ð��� �ʱ�ȭ��. */
	depature_time = depature_arr[0];
	arrival_time = arrival_arr[0];

	/* ���ÿ�, ù ��° �������� ��� �ð��� ������ �ð����̸� ù ��° �񱳰����� �ʱ�ȭ�� */
	time_gap1 = abs(depature_arr[0] - user_convert);

	/* ���� ������� ���ݱ��� �ִ� �ð��� ������(��߽ð� ����)�� �� ����
	 * �����Ͱ� ù ��° ���������� �ʱ�ȭ�Ǿ����Ƿ� �񱳴� ( 8 - 1 )�� �̷������.
     */
	for (i = 1; i < 8; i++) {

		/* ���� �������� ��� �ð��� ���� �ð����� ���̸� ����Ͽ� ���� */
		time_gap2 = abs(depature_arr[i] - user_convert);

		/* ���ݱ����� �ִ� �ð����� ���� �������� �ð������� ũ�ٸ�, �ִ� �ð����� ���� */
		if (time_gap1 > time_gap2) {
			time_gap1 = time_gap2;

			/* �ִ� �ð����� ��߽ð���, �׿� ���� ���� �ð��� ������. */
			depature_time = depature_arr[i];
			arrival_time = arrival_arr[i];
		}
	}

	/* ������ depature_time�� arrival_time(��� ������ ��ȯ�Ǿ�����)�� 12-�ð� �������� ��ȯ �� ���Ŀ� �°� ��� */
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