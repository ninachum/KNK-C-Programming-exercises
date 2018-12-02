#include <stdio.h>

int main(void)
{
	int num, div_1, div_2;
	char *from_twenty[] = { "twenty", "thirty", "forty", "fifthy", "seventy", "eighty", "ninty" };
	char *special_case[] = { "ten", "eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", "eighteen", "nineteen" };
	char *ones_place[] = { "one", "two", "three", "four", "five", "six", "seven", "eight", "nine" };

	printf("Enter a two-digit number: ");
	scanf("%d", &num);
	/* note that num is 10 ~ 99 */

	div_1 = num / 10;
	div_2 = num % 10;

	if (div_1 == 1) 
		printf("%s\n", special_case[div_2]);
	else 
		printf("%s %s\n", from_twenty[div_1 - 2], ones_place[div_2 - 1]);

	return 0;
}
