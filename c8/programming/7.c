/* program that reads a 5 x 5 array of integers,
 * and prints the row sums and the column sums
 */

#include <stdio.h>

/* for future array size change */
#define NUM_OF_ROW (((int) (sizeof(rowsum) / sizeof(rowsum[0]))))
#define NUM_OF_COL (((int) (sizeof(colsum) / sizeof(colsum[0]))))


int main(void)
{
	int i, j;
	int arr[5][5] = { 0 }, rowsum[5] = { 0 }, colsum[5] = { 0 };

	/* take a row at a time. calculating rowsum and colsum same time. */
	for (i = 0; i < NUM_OF_ROW; i++) {
		printf("Enter row %d: ", i + 1);
		for (j = 0; j < NUM_OF_COL; j++) {
			scanf(" %d", &arr[i][j]);
			rowsum[i] += arr[i][j];
			/* NOT colsum[i] ! */
			colsum[j] += arr[i][j];
		}
	}

	/* print rowsum */
	printf("Row totals: ");
	for (i = 0; i < NUM_OF_ROW; i++) {
		printf("%d ", rowsum[i]);
	}
	printf("\n");

	/* print colsum */
	printf("Column totals: ");
	for (i = 0; i < NUM_OF_COL; i++) {
		printf("%d ", colsum[i]);
	}
	printf("\n");


	return 0;

}