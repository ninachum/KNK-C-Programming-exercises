/* calculates SCRABBLE value. improved version(uses array) of 5.c in chapter 7 */

#include <stdio.h>
/* include ctype.h to use toupper(), which allows any mixture of lower-case and upper-case letters */
#include <ctype.h> 

int main(void)
{
	int svalue = 0;
	/* this array is reference value, corresponding to 26 letters of the alphabet. */
	const unsigned char ch[26] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 4, 10};
	unsigned char now_char;

	printf("Enter a word: ");
	
	/* calculates scrabble value of the word, while takes a character at a time until meets '\n' */
	while ((now_char = getchar()) != '\n')
		/* add a value that based on array 'ch'. index of 'ch' is mapped by [toupper(now_char) - 'A']
		 * toupper() is used to make conversion simple. */
		svalue += ch[toupper(now_char) - 'A'];

	printf("Scrabble value: %d\n", svalue);

	return 0;
}
