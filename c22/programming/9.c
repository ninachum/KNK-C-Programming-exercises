/* Note : most error-checking is omitted, for clarity. */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define NAME_LEN 25
#define MAX_PARTS 100

struct part {
	int number;
	char name[NAME_LEN + 1];
	int on_hand;
};

void *create_array(size_t size, int length);
long file_length(FILE *fp);
int compare_part_number(const void *p, const void *q);

int main(int argc, char *argv[])
{
	FILE *input, *merged, *result;
	bool *is_combined_for_merged;
	long input_length, merged_length, result_length;
	struct part *input_arr, *merged_arr;
	int i, j, temp;

	/* open two input files(input, merged) to merge, and another one to write result. */
	input = fopen(argv[1], "rb");
	merged = fopen(argv[2], "rb");
	result = fopen(argv[3], "wb");

	/* evaluate length (of array) for each file. */
	input_length = file_length(input) / sizeof(struct part);
	merged_length = file_length(merged) / sizeof(struct part);
	result_length = input_length + merged_length; // this is maximum length of resulting array.

	/* create arrays for storing data from two input file. */
	input_arr = create_array(sizeof(struct part), result_length);
	merged_arr = create_array(sizeof(struct part), merged_length);

	/* this array is a flag array for merged_arr.
	 * If an element of merged_arr is combined, its correspoding element of is_combined... will be set true.
	 * this array will be used for appending uncombined data (step 2).
	 */
	is_combined_for_merged = create_array(sizeof(bool), merged_length);
	for (i = 0; i < merged_length; i++)
		is_combined_for_merged[i] = false;

	/* store data from two input file to created arrays. */
	fread(input_arr, sizeof(struct part), input_length, input);
	fread(merged_arr, sizeof(struct part), merged_length, merged);

	/* with 'input_arr' as the base, merge 'merged_arr' to 'input_arr'.
	* [first step : only parts to be combined are merged.]
	*/
	for (i = 0; i < input_length; i++)
		for (j = 0; (j < merged_length) && (input_arr[i].number >= merged_arr[j].number); j++)
			/* if there's a matching part number */
			if (input_arr[i].number == merged_arr[j].number) {
				/* first, do a consistency check (whether part names match or not) */
				if (strcmp(input_arr[i].name, merged_arr[j].name) == 0) {
					is_combined_for_merged[j] = true;  // mark that jth element is combined. its corresponding element of merged_arr won't be appended in next process.
					input_arr[i].number += merged_arr[j].number;
					result_length--; // length of final result (array) will be decremented by 1, each time when combine is done.
				}

				/* initial consistency check fail leads to printing all inconsistent part number list and exiting program. */
				else {
					/* from where inconsitency has detected, find all inconsistency and print the list. */
					for (; i < input_length; i++) {
						temp = 1; // initialize the number of failure on a part number.
						for (; j < merged_length && input_arr[i].number >= merged_arr[j].number; j++)
							if (input_arr[i].number == merged_arr[j].number && strcmp(input_arr[i].name, merged_arr[j].name) != 0)
								printf("Consistency check failed : %dth fail on part number %d\n", temp++, input_arr[i].number);
					}
					fclose(input), fclose(merged), fclose(result);
					remove(argv[3]);
					exit(EXIT_FAILURE);
				}
			}

	/* [second step : append uncombined elements of 'merged_arr'.] */
	temp = input_length;
	for (i = 0; i < merged_length; i++) 
		if (!is_combined_for_merged[i]) 
			input_arr[temp++].on_hand = merged_arr[i].on_hand;
		
	

	/* [final step : sort and write.] */
	qsort(input_arr, result_length, sizeof(struct part), compare_part_number);
	fwrite(input_arr, sizeof(struct part), result_length, result);

	fclose(input), fclose(merged), fclose(result);

	return 0;
}

void *create_array(size_t size, int length)
{
	void *new_arrptr = malloc(size * length);

	return new_arrptr;
}

long file_length(FILE *fp)
{
	long result;
	fseek(fp, 0, SEEK_END);
	result = ftell(fp);
	fseek(fp, 0, SEEK_SET);
	return result;
}

int compare_part_number(const void *p, const void *q)
{
	return (((struct part *) p)->number - ((struct part*) q)->number);
}