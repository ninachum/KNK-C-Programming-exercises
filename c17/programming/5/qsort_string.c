/* sorts an array of pointers (char *) uing Quicksort algorithm */

#include <stdio.h>
#include <string.h>
#include "qsort_string.h"

void quicksort(char *a[], int low, int high)
{
	int middle;

	if (low >= high)
		return;
	middle = split(a, low, high);
	quicksort(a, low, middle - 1);
	quicksort(a, middle + 1, high);
}

int split(char *a[], int low, int high)
{
	char part_element[MAX_WORD_LEN + 1];
	strcpy(part_element, a[low]);

	for (;;) {
		while (low < high && strcmp(part_element, a[high]) <= 0) {
			high--;
		}
		if (low >= high)
			break;
		strcpy(a[low], a[high]);
		low++;

		while (low < high && strcmp(part_element, a[high]) >= 0) {
			low++;
		}
		if (low >= high)
			break;
		strcpy(a[high], a[low]);
		high--;
	}

	strcpy(a[high], part_element);
	return high;
}


