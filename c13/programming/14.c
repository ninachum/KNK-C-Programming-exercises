/* a program that tests whether two words are anagrams */

#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>
#include <string.h>

#define LENGTH 20

bool are_anagrams(const char *word1, const char *word2);

int main(void)
{
	char word1[LENGTH], word2[LENGTH];

	printf("Enter first word: ");
	fgets(word1, sizeof(word1), stdin);

	printf("Enter second word: ");
	fgets(word2, sizeof(word2), stdin);
	
	if (are_anagrams(word1, word2))
		printf("The words are anagrams.\n");
	else
		printf("The words are not anagrams\n");

	return 0;
}

bool are_anagrams(const char *word1, const char *word2)
{
	int i;

	/* indexes of seen_times[26] are corresponding to 26 letters of the alphabet. */
	int seen_times[26] = { 0 };

	while (*word1) {
		/* if *word1 is an alphabet, increase its corresponding counter by 1. */
		if (isalpha(*word1))
			seen_times[tolower(*word1 - 'a')] += 1;
		word1++;
	}

	while (*word2) {
		/* if *word2 is an alphabet, increase its corresponding counter by 1. */
		if (isalpha(*word2))
			seen_times[tolower(*word2 - 'a')] -= 1;
		word2++;
	}

	for (i = 0; i < 26; i++)
		if (seen_times[i] != 0)
			return 0;

	return 1;
}
