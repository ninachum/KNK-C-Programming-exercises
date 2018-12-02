#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#define LENGTH 100

bool is_palindrome(const char *message);

int main(void)
{
	char msg[LENGTH];

	printf("Enter a message: ");
	fgets(msg, sizeof(msg), stdin);
	if (*(msg + strlen(msg) - 1) == '\n')
		*(msg + strlen(msg) - 1) = '\0';

	if (is_palindrome(msg))
		printf("Palindrome\n");
	else
		printf("Not palindrome\n");
	
	return 0;
}

bool is_palindrome(const char *message)
{
	const char *p = message + strlen(message) - 1;

	/* p now indicates last valid character. */

	while (message < p) {
		if (*message != *p)
			return 0;

		message++, p--;
	}

	return 1;
}

