/* a program that finds the 'smallest' and 'largest' in a series of words. */

#include <stdio.h>
#include <string.h>

#define LENGTH 20

void decide_smallest_largest(char *smallest, char *largest, const char *compare);

int main(void)
{
	char smallest[LENGTH + 1], largest[LENGTH + 1];
	char compare[LENGTH + 1];
	
	printf("Enter a word (4-length word to end): ");
	fgets(compare, sizeof(compare), stdin);
	strcpy(smallest, compare);
	strcpy(largest, compare);

	for (;;) {
		/* we've used 5, which is 4 + 1, because fgets() saves '\n' in a string.
		 * (while, gets() discards '\n')
		 * thus, if we're intended to use 4-letter word as a terminating word,
		 * we must use 5, which is (4 + 1, 4 for 4-letter word, and additional 1 for '\n')
		 */
		if (strlen(compare) == 5)
			break;

		printf("Enter a word (4-length word to end): ");
		fgets(compare, sizeof(compare), stdin);
		decide_smallest_largest(smallest, largest, compare);
	}

	printf("\nSmallest word: %s\n", smallest);
	printf("Largest word: %s\n", largest);

	return 0;
}

void decide_smallest_largest(char *smallest, char *largest, const char *compare)
{
	if (strcmp(smallest, compare) > 0)
		strcpy(smallest, compare);
	else if (strcmp(largest, compare) < 0)
		strcpy(largest, compare);
}