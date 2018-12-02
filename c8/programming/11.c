/* Program that translates an alphabetic phone number into numeric form.
* (assuming any letters entered by user are upper case)
* Do not change non-alphabetic part of input.
* (Q and Z are omitted in this program.)
*/

#include <stdio.h>

int main(void)
{
	unsigned char ch[15]; // don't forget to explicitly use signed char or unsigned char.
	int i;
	printf("Enter phone number: ");

	/* save string and print */
	for (i = 0; (ch[i] = getchar()) != '\n' && i < 15; i++) {

		if (i == 0)
			printf("In numeric form: ");

		/* print output depending on the value of ch[i]. */
		switch (ch[i]) {
		case 65: case 66: case 67: // 2 = ABC
			putchar('2');
			break;
		case 68: case 69: case 70: // 3 = DEF
			putchar('3');
			break;
		case 71: case 72: case 73: // 4 = GHI
			putchar('4');
			break;
		case 74: case 75: case 76: // so on...
			putchar('5');
			break;
		case 77: case 78: case 79:
			putchar('6');
			break;
		case 80: case 82: case 83: // 7 = PRS. Q is omitted. (which is 81)
			putchar('7');
			break;
		case 84: case 85: case 86:
			putchar('8');
			break;
		case 87: case 88: case 89: // 9 = WXY
			putchar('9');
			break;
		default:				   // print a character without changing the input, if the input is non-alphabetic
			putchar(ch[i]);
			break;
		}

	}
	printf("\n");

	return 0;
}