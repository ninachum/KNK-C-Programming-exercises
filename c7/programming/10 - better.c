/* counts the number of vowels(a,e,i,o,u) in a sentence. */

#include <stdio.h>
#include <ctype.h>

int main(void)
{
	int a = 0;
	char ch;

	printf("Enter a sentence: ");

	/* read a character from buffer, saving it to ch, and check whether it is a new-line char. */
	while((ch = getchar()) != '\n') {
		switch(toupper(ch)) {
			case 'A': case 'E': case 'I': case 'O': case 'U':
				a++;
				break;
		}
	}

	printf("Your sentence contains %d vowels.\n", a);

	return 0;
}