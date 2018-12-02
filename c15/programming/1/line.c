#include <stdio.h>
#include <string.h>
#include "line.h"

#define MAX_LINE_LEN 60

char line[MAX_LINE_LEN + 1];
int line_len = 0;
int num_words = 0;

void clear_line(void)
{
	line[0] = '\0';
	line_len = 0;
	num_words = 0;
}

void add_word(const char *word)
{
	if (num_words > 0) {
		line[line_len] = ' ';
		line[line_len + 1] = '\0';
		line_len++;
	}
	strcat(line, word);
	line_len += strlen(word);
	num_words++;
}

int space_remaining(void)
{
	return MAX_LINE_LEN - line_len;
}

void write_line(void)
{
	int extra_spaces, equal_spaces_to_insert, i, j;
	int not_equal_spaces_tails, not_equal_spaces_heads, not_equal_spaces_to_insert;
	int nth_space = 1;

	extra_spaces = MAX_LINE_LEN - line_len;
	equal_spaces_to_insert = extra_spaces / (num_words - 1);
	not_equal_spaces_to_insert = extra_spaces % (num_words - 1);
	not_equal_spaces_heads = not_equal_spaces_to_insert / 2;
	not_equal_spaces_tails = (not_equal_spaces_to_insert % 2 == 0) ? (num_words - 1) - (not_equal_spaces_to_insert / 2) + 1 : (num_words - 1) - (not_equal_spaces_to_insert / 2);

	for (i = 0; i < line_len; i++) {
		if (line[i] != ' ')
			putchar(line[i]);
		else {
			for (j = 1; j <= equal_spaces_to_insert + 1; j++)
				putchar(' ');
			extra_spaces -= equal_spaces_to_insert;
			if (nth_space <= not_equal_spaces_heads || not_equal_spaces_tails <= nth_space) {
				putchar(' ');
				extra_spaces--;
			}
			nth_space++;
		}
	}
	putchar('\n');
}

void flush_line(void)
{
	if (line_len > 0)
		puts(line);
}