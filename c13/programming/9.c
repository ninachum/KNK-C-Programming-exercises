/* counts the number of vowels(a,e,i,o,u) in a sentence. */

#include <stdio.h>
#include <ctype.h>

#define SEN_LENGTH 30

int compute_vowel_count(const char *sentence);

int main(void)
{
	int a = 0;
	char sentence[SEN_LENGTH + 1];

	printf("Enter a sentence: ");
	fgets(sentence, sizeof(sentence), stdin);

	printf("Your sentence contains %d vowels.\n", compute_vowel_count(sentence));

	return 0;
}

int compute_vowel_count(const char *sentence)
{
	int counter = 0;

	while(*sentence) {
		switch(toupper(*sentence++)) {
			case 'A': case 'E': case 'I': case 'O': case 'U':
				counter++;
				break;
		}
	}

	return counter;
}