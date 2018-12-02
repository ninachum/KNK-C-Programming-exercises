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

/* find the largest element in an array, then save only its index in largest_index.
 * then, swap the element of largest_index with the last element of array.
 *
 * each time calling selection_sort(), array length is decreased by 1.
 */

void selection_sort(int arr[], int size)
{
	int i, largest_index = 0, largest;

	if (size == 1)
		return;

	for (i = 1; i < size - 1; i++) {
		if (arr[largest_index] < arr[i])
			largest_index = i;
	}
	largest = arr[largest_index];
	arr[largest_index] = arr[size - 1];
	arr[size - 1] = largest;

	selection_sort(arr, size - 1);
}
