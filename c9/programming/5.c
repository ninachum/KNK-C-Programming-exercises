/* program that prints an n x n magic square
* (a square arrangement of numbers 1, 2, ... n^2 in which the sums of the row, columns, and diagonals are all the same.)
*/

#include <stdio.h>

void create_magic_square(int n, unsigned char magic_square[99][99]);
void print_magic_square(int n, unsigned char magic_square[99][99]);

int main(void)
{
	int square_size;
	unsigned char arr[99][99] = { 0 };

	printf("This program creates a magic square of a specified size.\n");
	printf("The size must be an odd number between 1 and 99.\n");
	printf("Enter size of magic square: ");
	scanf("%d", &square_size);

	create_magic_square(square_size, arr);

	print_magic_square(square_size, arr);

	return 0;
}

void create_magic_square(int n, unsigned char magic_square[99][99])
{
	int now_row, now_col, now_num, b_row, b_col;

	/* initialization */
	now_row = 0;
	now_col = (n / 2);
	now_num = 1;
	magic_square[now_row][now_col] = now_num;

	for (;;) {
		now_num += 1;
		if (now_num == (n  * n + 1))
			break;

		/* save last position before move pointer */
		b_row = now_row;
		b_col = now_col;

		/* move pointer, while any attempt to move outside the bounds of array "wrap around". */
		now_row -= 1;
		now_col += 1;
		if (now_row < 0)
			now_row = (n - 1);
		if (now_col >(n - 1))
			now_col = 0;


		if (magic_square[now_row][now_col] == 0)
			magic_square[now_row][now_col] = now_num;
		/* if a particular array element is already occupied, change pointer directly below the saved last position */
		else {
			while (magic_square[b_row][b_col] != 0) {
				b_row += 1;
				if (b_row > (n - 1))
					b_row = 0;
			}
			/* don't forget to change pointer */
			now_row = b_row;
			now_col = b_col;
			/* also, don't forget to save the value. */
			magic_square[now_row][now_col] = now_num;
		}
	}
}

void print_magic_square(int n, unsigned char magic_square[99][99])
{
	int i, j;

	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			printf("%4d", magic_square[i][j]);
		}
		printf("\n");
	}
}