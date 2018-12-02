#include "readline.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "qsort_string.h"

#define INIT_MAX_WORDS 10

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

	quicksort(arr, 0, i - 1);


	printf("\nIn sorted order:");
	for (j = 0; j < i; j++)
		printf(" %s", arr[j]);

	return 0;

}


