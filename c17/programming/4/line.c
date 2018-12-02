#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "line.h"

#define MAX_LINE_LEN 60

struct word {
	char *str;
	struct word *next;
};

struct word *line = NULL;
int line_len = 0;
int num_words = 0;

void clear_line(void)
{
	struct word *prev, *cur;

	if (line != NULL) {
		for (prev = line, cur = line->next;
			 cur != NULL;
			 prev = cur, cur = cur->next)
			free(prev);
		free(prev);
		line = NULL;
		line_len = 0;
		num_words = 0;
	}

}

void add_word(const char *word)
{
	int length = strlen(word) + 1;
	struct word *last_node;
	struct word *new_word = malloc(sizeof(struct word));
	if (new_word == NULL) {
		printf("memory allocation failed.\n");
		exit(EXIT_FAILURE);
	}
	new_word->str = malloc(length * sizeof(char));
	strcpy(new_word->str, word);
	line_len += length - 1; // only strlen(word), not null.
	if (num_words > 0)		// plus 'virtual' space, which won't be stored, but printed in write_line() and flush_line().
		line_len++;
	num_words++;

	if (line != NULL) {
		for (last_node = line; last_node->next != NULL; last_node = last_node->next)
			;
		last_node->next = new_word;
	}
	else
		line = new_word;
	new_word->next = NULL;
		
	
}

int space_remaining(void)
{
	return MAX_LINE_LEN - line_len;
}

void write_line(void)
{
	int extra_spaces, spaces_to_insert, j;
	struct word *cur;

	extra_spaces = MAX_LINE_LEN - line_len;

	for (cur = line; cur != NULL; cur = cur->next) {
		printf("%s", cur->str);
		if (num_words > 1) {
			spaces_to_insert = extra_spaces / (num_words - 1);
			for (j = 1; j <= spaces_to_insert + 1; j++)
				putchar(' ');
			extra_spaces -= spaces_to_insert;
		}
		num_words--;
	}

	putchar('\n');
}
/*
	for (i = 0; cur->str[i] != '\0'; i++) {
		if (cur->str[i] != ' ')
			putchar(cur->str[i]);
		else {
			spaces_to_insert = extra_spaces / (num_words - 1);
			for (j = 1; j <= spaces_to_insert + 1; j++)
			putchar(' ');
			extra_spaces -= spaces_to_insert;
			num_words--;
		}
	}

		
*/
void flush_line(void)
{
	struct word *cur;

	if (line_len > 0)
		for (cur = line; cur != NULL; cur = cur->next) {
			printf("%s", cur->str);
			if (num_words > 1)
				putchar(' ');
			num_words--;
		}
}