#include <stdio.h>
#include <ctype.h>

int main(void)
{
	int a = 0;
	char ch;

	printf("Enter a sentence: ");
	ch = getchar();

	for(;;) {
		if(ch == '\n')
			break;

		switch(toupper(ch)) {
			case 'A': case 'E': case 'I': case 'O': case 'U':
				a++;
				break;
		}

		ch = getchar();

	}

	printf("Your sentence contains %d vowels.\n", a);

	return 0;
}