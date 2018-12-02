#include <stdio.h>
#include <string.h>

#define LENGTH 100

void reverse(char *message);

int main(void)
{
	signed char msg[LENGTH];

	printf("Enter a message: ");
	fgets(msg, sizeof(msg), stdin);
	if (*(msg + strlen(msg) - 1) == '\n')
		*(msg + strlen(msg) - 1) = '\0';

	reverse(msg);
	printf("Reversal is: %s\n", msg);


	return 0;
}

void reverse(char *message)
{
	char *p = message;
	char temp;

	while (*(p + 1))
		p++;

	/* now p indicates last valid character in message. */

	while (message < p) {
		temp = *message;
		*message = *p;
		*p = temp;
		message++, p--;
	}

}