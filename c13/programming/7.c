#include <stdio.h>

int main(void)
{
	int num, div_1, div_2;
	char *from_twenty[] = { "twenty", "thirty", "forty", "fifthy", "seventy", "eighty", "ninty" };
	char *special_case[] = { "ten", "eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", "eighteen", "nineteen" };
	char *ones_place[] = { "zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine" };

	printf("Enter a two-digit number: ");
	scanf("%d", &num);

	div_1 = num / 10;
	div_2 = num % 10;

	if (div_1 == 1) {
		printf("%s\n", special_case[div_2]);
		return 0;
	}
	else if (div_1 == 0)
		;
	else
		printf("%s", from_twenty[div_1 - 2]);

	if (div_1 != 0 && div_2 == 0)
		printf("\n");
	else
		printf(" %s\n", ones_place[div_2]);

	return 0;
}
