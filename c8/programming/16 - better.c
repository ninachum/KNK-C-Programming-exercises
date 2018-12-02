/* a program that tests whether two words are anagrams */

#include <stdio.h>
#include <ctype.h>

int main(void)
{
	/* indexes of seen_times[26] are corresponding to 26 letters of the alphabet. */
	int seen_times[26] = { 0 }, i;
	unsigned char now_char;


	printf("Enter first word: ");
	for (i = 0; ((now_char = getchar()) != '\n') && i < 20; i++) {

		/* if char_arr[i] is an alphabet, increase its corresponding counter by 1. */
		if (isalpha(now_char)) {
			seen_times[tolower(now_char - 'a')] += 1;
		}

	}

	printf("Enter second word: ");
	for (i = 0; ((now_char = getchar()) != '\n') && i < 20; i++) {

		/* if char_arr[i] is an alphabet, decrease its corresponding counter by 1. */
		if (isalpha(now_char)) {
			seen_times[tolower(now_char - 'a')] -= 1;
		}

	}

	for (i = 0; i < 26; i++) {
		if (seen_times[i] != 0) {
			printf("The words are not anagrams\n");
			return 0;
		}
	}
	if (i == 26)
		printf("The words are anagrams.\n");

	return 0;
}
