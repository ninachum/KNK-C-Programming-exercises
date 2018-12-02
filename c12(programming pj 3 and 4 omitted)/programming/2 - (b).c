#include <stdio.h>
#include <ctype.h>

int main(void)
{
	signed char ch, msg[100];
	signed char *p, *msg_last_pointer;

	printf("Enter a message: ");
	p = msg;
	while((ch = toupper(getchar())) != '\n')
	{
		if ('A' <= ch && ch <= 'Z')
			*p++ = ch;
	}
	p--;
	msg_last_pointer = p;
	p = msg;
	while(p <= msg_last_pointer)
	{
		if (*p != *msg_last_pointer) {
			printf("Not a palindrome\n");
			break;
		}
		p++;
		msg_last_pointer--;
	}
	if (p > (msg_last_pointer))
		printf("Palindrome\n");

	return 0;
}