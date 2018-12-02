/* Prints a one-month reminder list */

#include <stdio.h>
#include <string.h>

#define MAX_REMIND 50
#define MSG_LEN 60

int read_line(char str[], int n);

int main(void)
{
	/* 12 = (6 + 7 + (MSG_LEN + 1) - 1 - 1), -1 is for warpped over character('\0') */
	char reminders[MAX_REMIND][MSG_LEN + 12]; 

	/* day_str[6] for MM/DD'\0', time_str[7] for a blank space, and HH:MM'\0',
	 * msg_str[MSG_LEN + 1] for MSG_LEN characters and '\0'
	 */
	char day_str[6], time_str[7], msg_str[MSG_LEN + 1];
	
	/* temporary string, to sort reminder list by DATE && TIME.
	 * 12 = MM/DD_HH:MM'\0', which is 6 + 7 - 1 */
	char temp_str_for_sort[12];
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
		if (day < 0 || day > 31 || month > 12 || month < 1) {
			printf("Enter correct day.\n");
			/* flush buffer */
			while (getchar() != '\n');
			continue;
		}
		/* day_str needs 6 char spaces. */
		sprintf(day_str, "%.2d/%.2d", month, day);
		
		scanf("%2d : %2d", &hour, &minute);
		if (hour == 24 || hour < 0 || minute < 0 || minute >= 60) {
			printf("only 00:00 - 23:59 is valid.\n");
			/* flush buffer */
			while (getchar() != '\n');
			continue;
		}
		/* time_str needs 7 char spaces. */
		sprintf(time_str, " %.2d:%.2d", hour, minute);

		read_line(msg_str, MSG_LEN);

		/* find entry space for the new entry, by comparing date && time (as a string). */
		for (i = 0; i < num_remind; i++)
			if (strcmp(strcat(strcpy(temp_str_for_sort, day_str), time_str), reminders[i]) < 0)
				break;
		for (j = num_remind; j > i; j--)
			strcpy(reminders[j], reminders[j - 1]);

		strcpy(reminders[i], day_str);
		strcat(reminders[i], time_str);
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