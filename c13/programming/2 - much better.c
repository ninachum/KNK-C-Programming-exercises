/* Prints a one-month reminder list */

#include <stdio.h>
#include <string.h>

#define MAX_REMIND 50    // maximum number of entries
#define MSG_LEN 60       // maximum length of a reminder message
#define DATE_TIME_LEN 12 // length needed to store MM/DD_HH:MM'\0' format.

int read_line(char str[], int n);

int main(void)
{
	char reminders[MAX_REMIND][MSG_LEN + DATE_TIME_LEN]; 
	char date_and_time[DATE_TIME_LEN], msg_str[MSG_LEN + 1];
	int month, day, hour, minute, i, j, num_remind = 0;

	for (;;) {
		if (num_remind == MAX_REMIND) {
			printf("-- No space left --\n");
			break;
		}

		printf("Enter a month, day, time and reminder(0/0 to exit) \nformat: 'mm/dd hh:mm message' :");
		scanf("%2d / %2d", &month, &day);
		if (month == 0 && day == 0)
			break;
		scanf("%2d : %2d", &hour, &minute);
		if (day < 0 || day > 31 || month > 12 || month < 1 || hour == 24 || hour < 0 || minute < 0 || minute >= 60) {
			printf("Enter correct date and time.\n");
			/* flush buffer */
			while (getchar() != '\n');
			continue;
		}
		sprintf(date_and_time, "%.2d/%.2d %.2d:%.2d", month, day, hour, minute);

		read_line(msg_str, MSG_LEN);

		/* find entry space for the new entry, by comparing date && time (as a string). */
		for (i = 0; i < num_remind; i++)
			if (strcmp(date_and_time, reminders[i]) < 0)
				break;
		for (j = num_remind; j > i; j--)
			strcpy(reminders[j], reminders[j - 1]);

		strcpy(reminders[i], date_and_time);
		strcat(reminders[i], msg_str);

		num_remind++;
	}

	printf("\n Day   Time  Reminder\n");
	for (i = 0; i < num_remind; i++)
		printf(" %s\n", reminders[i]);

	return 0;
}

/* takes input from user, then write the characters to str[], while discarding exceed characters. */
int read_line(char str[], int n)
{
	int ch, i = 0;

	while ((ch = getchar()) != '\n')
		if (i < n)
			str[i++] = ch;
	str[i] = '\0';

	return i;
}