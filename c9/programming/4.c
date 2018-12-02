/* a program that tests whether two words are anagrams */

#include <stdio.h>
#include <ctype.h>

#define TRUE 1
#define FALSE 0

/* 26 indexes are corresponding to 26 letters of the alphabet. */
void read_word(int counts[26]);
int equal_array(int counts1[26], int counts2[26]);

int main(void)
{
	int first_alphabet_counter[26], second_alphabet_counter[26];

	printf("Enter first word: ");
	read_word(first_alphabet_counter);

	printf("Enter second word: ");
	read_word(second_alphabet_counter);

	if (equal_array(first_alphabet_counter, second_alphabet_counter))
		printf("they are anagrams.\n");
	else
		printf("they are not anagrams.\n");

	return 0;
}

void read_word(int counts[26])
{
	unsigned char now_char;
	int i;

	for (i = 0; ((now_char = getchar()) != '\n') && i < 20; i++) {

		/* if now_char is an alphabet, increase its corresponding counter by 1. */
		if (isalpha(now_char)) {
			counts[tolower(now_char - 'a')] += 1;
		}

	}
}

int equal_array(int counts1[26], int counts2[26])
{
	int i;

	/* compare two arrays, whether they are identical or not. */
	for (i = 0; i < 26; i++) {
		if (counts1[i] != counts2[i])
			return FALSE;
	}
	return TRUE;
}