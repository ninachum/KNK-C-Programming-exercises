/* Formats a file of text */

#include <string.h>
#include <stdlib.h>
#include "line.h"
#include "word.h" 

#define MAX_WORD_LEN 20

int main(void)
{
	char temp_word[MAX_WORD_LEN + 2];
	int word_len;

	clear_line();
	for (;;) {
		read_word(temp_word, MAX_WORD_LEN + 1);
		word_len = strlen(temp_word);
		if (word_len == 0) {
			flush_line();
			return 0;
		}
		if (word_len > MAX_WORD_LEN)
			temp_word[MAX_WORD_LEN] = '*';
		if (word_len + 1 > space_remaining()) {
			write_line();
			clear_line();
		}
		add_word(temp_word);
	}

	return 0;
}