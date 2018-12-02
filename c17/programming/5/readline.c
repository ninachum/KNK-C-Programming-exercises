#include <ctype.h>
#include <stdio.h>
#include "readline.h"

int read_line(char str[], int n)
{
	int ch, i = 0;

	while (isspace(ch = getchar()))
		if (ch == '\n') // this if-statement is a modified part. (compared to original readline.c of textbook.)
			break;

	while (ch != '\n' && ch != EOF) {
		if (i < n)
			str[i++] = ch;
		ch = getchar();
	}
	str[i] = '\0';
	return i;
}