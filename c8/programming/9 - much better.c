/* a program that generates a "random work(A to Z)" across a 10 x 10 array. */

#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define BLANK '.'
#define NUM_OF_ROW 10
#define NUM_OF_COL 10
#define TRUE 1
#define FALSE 0
#define ALL_BLOCK (blocked[0] == TRUE && blocked[1] == TRUE && blocked[2] == TRUE && blocked[3] == TRUE)

int main(void)
{
	unsigned char arr[NUM_OF_ROW][NUM_OF_COL], now_char;
	int i, j, row, col, blocked[4] = { FALSE }, next_move;

	for (i = 0; i < NUM_OF_ROW; i++) {
		for (j = 0; j < NUM_OF_COL; j++) {
			arr[i][j] = BLANK;
		}
	}

	srand((unsigned)time(NULL));

	/* initializing */
	row = rand() % 10;
	col = rand() % 10;
	now_char = 'A';
	arr[row][col] = now_char;

	/* loop for creating path */
	while (now_char < 'Z' && ALL_BLOCK == FALSE) {
		next_move = rand() % 4;

		/* check if the position of next move is valid and empty */
		switch (next_move) {
		case 0: // UP
			if ((row - 1) >= 0 && arr[row - 1][col] == BLANK) {
				row--;
			}
			else {
				blocked[next_move] = TRUE;
				continue;
			}
			break;

		case 1: // RIGHT
			if ((col + 1) <= (NUM_OF_COL - 1) && arr[row][col + 1] == BLANK) {
				col++;
			}
			else {
				blocked[next_move] = TRUE;
				continue;
			}
			break;

		case 2: // DOWN
			if ((row + 1) <= (NUM_OF_ROW - 1) && arr[row + 1][col] == BLANK) {
				row++;
			}
			else {
				blocked[next_move] = TRUE;
				continue;
			}
			break;

		case 3: // LEFT
			if ((col - 1) >= 0 && arr[row][col - 1] == BLANK) {
				col--;
			}
			else {
				blocked[next_move] = TRUE;
				continue;
			}
			break;
		}

		/* if the position is valid and empty, set a next character to the position. */
		now_char++;
		arr[row][col] = now_char;

		/* clear the blocked check */
		for (i = 0; i < 4; i++)
			blocked[i] = FALSE;
	}

	/* print the array. */
	for (i = 0; i < NUM_OF_ROW; i++) {
		for (j = 0; j < NUM_OF_COL; j++) {
			printf(" %c", arr[i][j]);
		}
		printf("\n");
	}

	return 0;
}