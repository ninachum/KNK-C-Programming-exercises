#include <stdio.h>

int main(void)
{
	signed char ch;
	signed char msg[100];
	int i = 0;

	printf("Enter a message: ");
	while((ch = getchar()) != '\n')
	{
		msg[i++] = ch;
	}

	i--;
	printf("Reversal is: ");
	while(i >= 0)
	{
		printf("%c", msg[i]);
		i--;
	}

	return 0;
}