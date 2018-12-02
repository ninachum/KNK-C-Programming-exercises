#include <stdio.h>
#include <ctype.h>

int main(void)
{
	signed char ch, msg[100];
	int i, msg_last_index;

	printf("Enter a message: ");
	i = 0;
	while((ch = toupper(getchar())) != '\n')
	{
		if ('A' <= ch && ch <= 'Z')
			msg[i++] = ch;
	}
	i--;
	msg_last_index = i;
	i = 0;
	while(i <= (msg_last_index - i))
	{
		if (msg[i] != msg[msg_last_index - i]) {
			printf("Not a palindrome\n");
			break;
		}
		i++;
	}
	if (i > (msg_last_index - i))
		printf("Palindrome\n");

	return 0;
}