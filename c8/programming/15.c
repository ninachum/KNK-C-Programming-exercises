/* program that encrypt plain text to Caesar cipher.
 * character other than letters will be left unchanged.
 * upper-case and lower-case, too.
 */

#include <stdio.h>

int main(void)
{
	int i, shift_amount;
	unsigned char char_arr[80], now_char;

	/* takes a string, and save it to char_arr. */
	printf("Enter message to be encrypted: ");
	for (i = 0; i < 80; i++) {
		now_char = getchar();
		char_arr[i] = now_char;
		if (now_char == '\n')
			break;
	}
	
	/* decide how many positions later for the string to be replaced. */
	printf("Enter shift amount (1 - 25): ");
	scanf("%d", &shift_amount);

	/* encrypting */
	for (i = 0; i < 80; i++) {
		if (char_arr[i] == '\n')
			break;

		if ('a' <= char_arr[i] && char_arr[i] <= 'z') {
			/* character will "wrap around" if it exceeds 'Z' */
			char_arr[i] = ((char_arr[i] - 'a') + shift_amount) % 26 + 'a';
		}
		else if ('A' <= char_arr[i] && char_arr[i] <= 'Z') {
			char_arr[i] = ((char_arr[i] - 'A') + shift_amount) % 26 + 'A';
		}
	}


	printf("Encrypted message: ");
	for (i = 0; i < 80; i++) {
		if (char_arr[i] == '\n') {
			putchar('\n');
			break;
		}

		putchar(char_arr[i]);
	}

	return 0;
}


