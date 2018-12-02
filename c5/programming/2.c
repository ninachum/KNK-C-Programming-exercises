#include <stdio.h>

int main(void)
{
	int hour, minute;

	printf("Enter a 24-hour time [xx:xx]: ");
	scanf("%d : %d", &hour, &minute);

	if(hour < 12) // for AM
	{
		if(hour == 0) // special case, 0:00 AM is...
			hour = 12; // 12:00 AM.
		printf("Equivalent 12-hour time: %.2d:%.2d AM\n", hour, minute); // print "hour:minute AM"
	}
	else // for PM
	{
		if(hour > 12) // except 12:00 PM (12:00), all PM hours must be subtracted 12. 
			hour -= 12;
		printf("Equivalent 12-hour time: %.2d:%.2d PM\n", hour, minute);
	}

	return 0;
}