/* Program that translates an alphabetic phone number into numeric form.
 * (assuming any letters entered by user are upper case)
 * Do not change input if input is non-alphabetic.
 * (Q and Z are omitted in this program.)
 */

#include <stdio.h>

int main(void)
{
	signed char ch; // don't forget to explicitly use signed char or unsigned char.
	
	printf("Enter phone number: ");

	ch = getchar(); // (BY USER) get a character or string into buffer. and read its first character.

	/* start reading a character repeatedly. */
	for(;;) {
		if(ch == 10)               // terminte loop if ch == \n. (new line character)
			break; 

		switch(ch) {
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
			putchar(ch);
			break;
		}

		ch = getchar(); // read next character.
	}

	return 0;
}