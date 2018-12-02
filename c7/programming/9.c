/* input : 12-hour time
 * output : 24-hour time
 */

#include <stdio.h>
#include <ctype.h>

int main(void)
{
	int hour, minute, i;
	char ch;

	printf("Enter a 12-hour time (XX:XX AM or PM): ");
	scanf("%d : %d", &hour, &minute);
	
	for(i = 0; i < 2; i++) {
		ch = getchar();

		if(toupper(ch) == 'A') {
			if(hour == 12)
				hour = 0;
			printf("Equivalent 24-hour time: %d:%d \n", hour, minute);
			break;
		}

		if(toupper(ch) == 'P') {
			if(hour < 12)
				hour += 12;
			printf("Equivalent 24-hour time: %d:%d \n", hour, minute);
			break;
		}
	}

	return 0;
}