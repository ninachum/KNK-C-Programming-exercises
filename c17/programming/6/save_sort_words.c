#include "readline.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORD_LEN 20
#define INIT_MAX_WORDS 10

/* please check this page before reading:
 * https://stackoverflow.com/questions/3489139/how-to-qsort-an-array-of-pointers-to-char-in-c
 */
int compare_strings(const void *p, const void *q);

int main(void)
{
	char temp[MAX_WORD_LEN + 1];

	/* confused? check the bottom of 420p. **arr is same as an array name of *arr[number], if we use **arr as an array of pointers.*/
	char **arr = malloc(INIT_MAX_WORDS * sizeof(char *));
	
	char *word;
	int i = 0, num_limit = INIT_MAX_WORDS, len, j;


	for (;;) {
		printf("Enter word: ");
		len = read_line(temp, MAX_WORD_LEN);
		if (len == 0)
			break;
		word = malloc(sizeof(char) * len + 1);
		strcpy(word, temp);

		arr[i++] = word;
		if (num_limit >= i) {
			arr = realloc(arr, (++num_limit) * sizeof(char **));
		}
	}
	/*
	 * why arr, not arr[0]? (1) : when we sort an array of 100 integer elements from 50th to 100th, we use..
	 *							  qsort(&a[50], 50, sizeof(a[0]), compar);
	 *							  we're passing a pointer to an integer as 'base'(first argument).
	 * why arr, not arr[0]? (2): we pass int* (or []) when we want to qsort an array of int, so
	 *						     we pass char ** (or *[]) when we want to qsort an array of char *.
	 */
	qsort(arr, i, sizeof(char *), compare_strings);
	/* !! qsort(&arr[0], i, sizeof(char *), compare_strings); is more clear, and it works, of course. !! */

	printf("\nIn sorted order:");
	for (j = 0; j < i; j++)
		printf(" %s", arr[j]);

	return 0;

}

int compare_strings(const void *p, const void *q)
{
	/* why *(const char **)p, not (const char *)p? : qsort is passed pointers to each element to compare function.
	 *												 since elements here are char *, compare_strings is passed char **.
	 */
	return strcmp(*(const char **)p, *(const char **)q);
}



