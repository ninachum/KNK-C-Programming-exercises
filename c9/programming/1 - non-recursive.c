/* a program that asks the user to enter a series of integers.
* then it sorts the integers by calling the function selection_sort(array_pointer, array_size)
*/

#include <stdio.h>

#define ARR_SIZE 5

void selection_sort(int arr[], int size);

int main(void)
{
	int arr[ARR_SIZE];
	int i;

	printf("Enter five integers: ");
	for (i = 0; i < ARR_SIZE; i++) {
		scanf(" %d", &arr[i]);
	}

	selection_sort(arr, ARR_SIZE);

	printf("sorted order: ");
	for (i = 0; i < ARR_SIZE; i++) {
		printf(" %d", arr[i]);
	}

	return 0;
}

void selection_sort(int arr[], int size)
{
	int largest, largeloc, i, j;

	for (i = size; i > 1; i--) {
		largest = arr[0];
		largeloc = 0;

		for (j = 1; j < i; j++) {
			if (largest < arr[j]) {
				largest = arr[j];
				largeloc = j;
			}
		}
		for (j = largeloc; j < i - 1; j++) {
			arr[j] = arr[j + 1];
		}
		arr[i - 1] = largest;
	}
}
