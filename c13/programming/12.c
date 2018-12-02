/* a program that stores the words in a two-dimensional char array as it reads the sentence,
 * with each row of the array storing a single word.
 * this is modified version of Programming Project 14 from Chapter 8.
 * ex) hey there. => there hey.
 */

#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define WORDS 30
#define LENGTH 20
#define LAST_VALID_CHAR_POINTER sentence + strlen(sentence) - 1

int save_words(char words[][LENGTH + 1], char *sentence);
void reverse_print_words(const char words[][LENGTH + 1], int num_words, char end_char);

int main(void)
{
	char words[WORDS][LENGTH + 1];
	char sentence[WORDS * LENGTH + 1];
	char end_char = '\0', *end_char_search;
	int num_words;

	printf("Enter a sentence: ");
	fgets(sentence, sizeof(sentence), stdin);

	/* if buffer input has ended by '\n', replace it with '\0' */
	if (*(LAST_VALID_CHAR_POINTER) == '\n')
		*(LAST_VALID_CHAR_POINTER) = '\0';
	/* search for terminating character to append to the end of resulting sentence. */
	for (end_char_search = LAST_VALID_CHAR_POINTER; end_char_search >= sentence; end_char_search--) 
		if (*end_char_search == '!' || *end_char_search == '?' || *end_char_search == '.') {
			end_char = *end_char_search;
			*end_char_search = '\0';
			break;
		}
	/* if there was no terminating char, return 0. */
	if (end_char == '\0') {
		printf("There's no terminating character.\n");
		return 0;
	}	

	num_words = save_words(words, sentence);
	reverse_print_words(words, num_words, end_char);

	return 0;
}

int save_words(char words[][LENGTH + 1], char *sentence)
{
	int i;
	char *last_word_point;

	/* a loop that searches white-space charcter or null character.
	 * when it finds one of them, it is end of a word. saves it in two-dimensional array.
	 */
	for (i = 0; i < WORDS; i++) {
		last_word_point = sentence;
		while (!isspace(*sentence) && *sentence != '\0')
			sentence++;
		if (*sentence == '\0') {
			strcpy(words[i], last_word_point);
			break;
		}
		*sentence++ = '\0';
		strcpy(words[i], last_word_point);

	}
	/* returns how many words it have stored */
	return i + 1;
}

void reverse_print_words(const char words[][LENGTH + 1], int num_words, char end_char)
{
	/* print words, in reverse order. */
	while (num_words >= 1) {
		/* if the word is last one, there's no need for appending ' ' to it. */
		if (num_words == 1) {
			printf("%s", words[num_words - 1]);
			break;
		}
		printf("%s ", words[num_words - 1]);
		num_words--;
	}
	/* append termincating character. */
	printf("%c\n", end_char);

}