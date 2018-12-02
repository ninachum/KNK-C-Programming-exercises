/* a program that search the array to find the largest element,
 * then move it to the last position in the array.
 * and, recursively call itself to sort the first n - 1 elements of the array.
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

/* find the largest element in an array, and its index too.
 * then, from the index of the largest one, to right before the last index of array, replace its element with its right element.
 * then move the largest element to the end of array.
 *
 * each time calling selection_sort(), array length is decreased by 1.
 */

void selection_sort(int arr[], int size)
{
	int i, largest, largeloc = 0;

	if (size == 1)
		return;

	largest = arr[0];
	for (i = 1; i < size; i++) {
		if (largest < arr[i]) {
			largest = arr[i];
			largeloc = i;
		}
	}
	for (i = largeloc; i < size - 1; i++) {
		arr[i] = arr[i + 1];
	}
	arr[size - 1] = largest;

	selection_sort(arr, size - 1);
}
