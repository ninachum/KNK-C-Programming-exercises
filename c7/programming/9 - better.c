/* input : 12-hour time
 * output : 24-hour time
 */

#include <stdio.h>
#include <ctype.h>

int main(void)
{
	int hour, minute;
	char ch;

	/* using scanf, get hour && minute && ch at once. */
	printf("Enter a 12-hour time (XX:XX AM or PM): ");
	scanf("%d : %d %c", &hour, &minute, &ch);
	
	if(toupper(ch) == 'A') {
		if(hour == 12)
			hour = 0;
		printf("Equivalent 24-hour time: %d:%d \n", hour, minute);
	}
	else if(toupper(ch) == 'P') {
		if(hour < 12)
			hour += 12;
		printf("Equivalent 24-hour time: %d:%d \n", hour, minute);
	}

	return 0;
}