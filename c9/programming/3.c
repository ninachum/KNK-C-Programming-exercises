#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define BLANK '.'
#define NUM_OF_ROW 10
#define NUM_OF_COL 10
#define TRUE 1
#define FALSE 0
#define ALL_BLOCK (blocked[0] == TRUE && blocked[1] == TRUE && blocked[2] == TRUE && blocked[3] == TRUE)

void generate_random_walk(unsigned char walk[NUM_OF_ROW][NUM_OF_COL]);
void print_array(unsigned char walk[NUM_OF_ROW][NUM_OF_COL]);

int main(void)
{
	unsigned char arr[NUM_OF_ROW][NUM_OF_COL];

	generate_random_walk(arr);

	print_array(arr);

	return 0;
}

void generate_random_walk(unsigned char walk[NUM_OF_ROW][NUM_OF_COL])
{
	unsigned char now_char;
	int i, j, row, col, blocked[4] = { FALSE }, next_move;

	for (i = 0; i < NUM_OF_ROW; i++) {
		for (j = 0; j < NUM_OF_COL; j++) {
			walk[i][j] = BLANK;
		}
	}

	srand((unsigned)time(NULL));

	/* initializing */
	row = rand() % NUM_OF_ROW;
	col = rand() % NUM_OF_COL;
	now_char = 'A';
	walk[row][col] = now_char;

	/* loop for creating path */
	while (now_char < 'Z' && ALL_BLOCK == FALSE) {
		next_move = rand() % 4;

		/* check if the position of next move is valid and empty */
		switch (next_move) {
		case 0: // UP
			if ((row - 1) >= 0 && walk[row - 1][col] == BLANK) {
				row--;
			}
			else {
				blocked[next_move] = TRUE;
				continue;
			}
			break;

		case 1: // RIGHT
			if ((col + 1) <= (NUM_OF_COL - 1) && walk[row][col + 1] == BLANK) {
				col++;
			}
			else {
				blocked[next_move] = TRUE;
				continue;
			}
			break;

		case 2: // DOWN
			if ((row + 1) <= (NUM_OF_ROW - 1) && walk[row + 1][col] == BLANK) {
				row++;
			}
			else {
				blocked[next_move] = TRUE;
				continue;
			}
			break;

		case 3: // LEFT
			if ((col - 1) >= 0 && walk[row][col - 1] == BLANK) {
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
		walk[row][col] = now_char;

		/* clear the blocked check */
		for (i = 0; i < 4; i++)
			blocked[i] = FALSE;
	}
}

void print_array(unsigned char walk[NUM_OF_ROW][NUM_OF_COL])
{
	int i, j;

	for (i = 0; i < NUM_OF_ROW; i++) {
		for (j = 0; j < NUM_OF_COL; j++) {
			printf(" %c", walk[i][j]);
		}
		printf("\n");
	}
}