/* Formats a file of text */

#include <string.h>
#include <stdlib.h>
#include "line.h"
#include "word.h"
#include "justify.h"

#define MAX_WORD_LEN 20

FILE *source, *dest;

int main(int argc, char *argv[])
{
	char word[MAX_WORD_LEN + 2];
	int word_len;

	if (argc !=  3) {
		printf("Usage : justify file1 file2");
		exit(EXIT_FAILURE);
	}
	if ((source = fopen(argv[1], "r")) == NULL) {
		printf("Can't open %s ", argv[1]);
		exit(EXIT_FAILURE);
	}
	if ((dest = fopen(argv[2], "w")) == NULL) {
		printf("Can't create %s ", argv[2]);
		exit(EXIT_FAILURE);
	}

	clear_line();
	for (;;) {
		read_word(word, MAX_WORD_LEN + 1);
		word_len = strlen(word);
		if (word_len == 0) {
			flush_line();
			return 0;
		}
		if (word_len > MAX_WORD_LEN)
			word[MAX_WORD_LEN] = '*';
		if (word_len + 1 > space_remaining()) {
			write_line();
			clear_line();
		}
		add_word(word);
	}

	fclose(source), fclose(dest);

	return 0;
}