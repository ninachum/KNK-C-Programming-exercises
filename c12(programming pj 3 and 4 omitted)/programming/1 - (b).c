#include <stdio.h>

int main(void)
{
	signed char ch;
	signed char msg[100];
	signed char *p;

	printf("Enter a message: ");
	p = msg;
	while((ch = getchar()) != '\n')
	{
		*p++ = ch;
	}

	p--;
	printf("Reversal is: ");
	while(p >= msg)
	{
		printf("%c", *p--);
	}

	return 0;
}