/* calculates the average word length for a sentence
 * (considering punctuation mark to be part of the word)
 */

#include <stdio.h>
#include <ctype.h>

int main(void)
{
	int sum_length = 0, word_count = 0;
	char ch;

	printf("Enter a sentence: ");
	
	/* skips space while getting an input from user */
	while((ch = getchar()) == ' ')
		;
	/* now, ch is first non-space letter of the input. */

	/* iteration starts. */
	for(;;) {
		/* if ch is a new-line character, exit the loop. */
		if(ch == '\n')
			break;

		/* if ch is a space, just read next character. */
		else if(ch == ' ')
			ch = getchar();

		/* if ch is an alphabet or punctuation, increment total letter number */
		else {
			sum_length++;

			/* and, read next character. */
			ch = getchar();
			/* If the letter that ch read next is space or new-line character, it is the end of a word.
			 * Then, increment word count.
			 */
			if(ch == ' ' || ch == '\n')
				word_count++;
		}
	}

	/* don't forget the two variables in this printf() call is int type. */
	printf("Average word length: %.1f\n", (float) sum_length / word_count);

	return 0;
}