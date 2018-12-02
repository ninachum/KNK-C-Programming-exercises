/* B1FF-translator. */

/* for toupper() */
#include <stdio.h>
#include <ctype.h>

#define LENGTH (((int) sizeof(ch) / sizeof(ch[0])))

int main(void)
{
	char ch[100];
	int i;

	printf("Enter message :");
	/* takes a string (ends with '\n') in buffer, and store it in ch */
	for (i = 0; i < LENGTH; i++) {
		ch[i] = getchar();
		if (ch[i] == '\n')
			break;
	}

	printf("In B1FF-speak: ");
	/* translate the string in ch, and print characters one by one. */
	for (i = 0; i < LENGTH; i++) {
		if (ch[i] == '\n')
			break;

		switch (toupper(ch[i])) {
		case 'A': putchar('4'); break;
		case 'B': putchar('8'); break;
		case 'E': putchar('3'); break;
		case 'I': putchar('1'); break;
		case 'O': putchar('0'); break;
		case 'S': putchar('5'); break;
		default: putchar(toupper(ch[i])); break;

		}
	}
	printf("!!!!!!!!!\n");

	return 0;

}