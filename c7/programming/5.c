/* very similar program to 4.c of the same chapter(7th)
 * check 4.c for comments.
 */

#include <stdio.h>
#include <ctype.h> 
/* include ctype.h to use toupper(), which allow any mixture of lower-case and upper-case letters */

int main(void)
{
	int svalue = 0;
	char ch;

	printf("Enter a word: ");
	ch = getchar();

	for(;;) {
		if(ch == 10)
			break;

		switch(toupper(ch)) {
		case 65: case 69: case 73: case 76: case 78: case 79: case 82: case 83: case 84: case 85:
				svalue += 1;
				break;
			case 68: case 71:
				svalue += 2;
				break;
			case 66: case 67: case 77: case 80:
				svalue += 3;
				break;
			case 70: case 72: case 86: case 87: case 89:
				svalue += 4;
				break;
			case 75:
				svalue += 5;
				break;
			case 74: case 88:
				svalue += 8;
				break;
			case 81: case 90:
				svalue += 10;
				break;
		}

		ch = getchar();
	}

	printf("Scrabble value: %d\n", svalue);

	return 0;
}
