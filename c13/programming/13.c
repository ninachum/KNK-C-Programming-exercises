/* program that encrypt plain text to Caesar cipher.
* character other than letters will be left unchanged.
* upper-case and lower-case, too.
*/

#include <stdio.h>
#include <string.h>

#define LAST_VALID_CHAR_POINTER char_arr + strlen(char_arr) - 1 
#define LENGTH 80

void encrypt(char *message, int shift);

int main(void)
{
	int shift_amount;
	char char_arr[LENGTH - 1];

	/* takes a string, and save it to char_arr. */
	printf("Enter message to be encrypted: ");
	fgets(char_arr, sizeof(char_arr), stdin);
	if (*(LAST_VALID_CHAR_POINTER) == '\n')
		*(LAST_VALID_CHAR_POINTER) = '\0';

	/* decide how many positions later for the string to be replaced. */
	printf("Enter shift amount (1 - 25): ");
	scanf("%d", &shift_amount);
	
	/* encrypting */
	encrypt(char_arr, shift_amount);

	printf("Encrypted message: %s\n", char_arr);

	return 0;
}

void encrypt(char *message, int shift)
{
	while (*message) {
		if (*message == '\0')
			break;

		if ('a' <= *message && *message <= 'z') {
			/* character will "wrap around" if it exceeds 'Z' */
			*message = ((*message - 'a') + shift) % 26 + 'a';
		}
		else if ('A' <= *message && *message <= 'Z') {
			*message = ((*message - 'A') + shift) % 26 + 'A';
		}

		message++;
	}
}
