/* program that prints an n x n magic square
 * (a square arrangement of numbers 1, 2, ... n^2 in which the sums of the row, columns, and diagonals are all the same.)
 */

#include <stdio.h>

int main(void)
{
	int arr[99][99] = { 0 }, now_row, now_col, square_size, now_num, i, j, b_row, b_col;

	printf("This program creates a magic square of a specified size.\n");
	printf("The size must be an odd number between 1 and 99.\n");

	printf("Enter size of magic square: ");
	scanf("%d", &square_size);

	/* initialization */
	now_row = 0;
	now_col = (square_size / 2);
	now_num = 1;
	arr[now_row][now_col] = now_num;

	for (;;) {
		now_num += 1;
		if (now_num == (square_size  * square_size + 1))
			break;

		/* save last position before move pointer */
		b_row = now_row;
		b_col = now_col;

		/* move pointer, while any attempt to move outside the bounds of array "wrap around". */
		now_row -= 1;
		now_col += 1;
		if (now_row < 0)
			now_row = (square_size - 1);
		if (now_col > (square_size - 1))
			now_col = 0;

		
		if (arr[now_row][now_col] == 0)
			arr[now_row][now_col] = now_num;
		/* if a particular array element is already occupied, change pointer directly below the saved last position */
		else {
			while (arr[b_row][b_col] != 0) {
				b_row += 1;
				if (b_row > (square_size - 1))
					b_row = 0;
			}
			/* don't forget to change pointer */
			now_row = b_row;
			now_col = b_col;
			/* also, don't forget to save the value. */
			arr[now_row][now_col] = now_num;
		}
	}

	for (i = 0; i < square_size; i++) {
		for (j = 0; j < square_size; j++) {
			printf("%4d", arr[i][j]);
		}
		printf("\n");
	}

	return 0;
}



