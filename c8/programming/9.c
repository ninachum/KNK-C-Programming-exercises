/* a program that generates a "random work(A to Z)" across a 10 x 10 array. */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void)
{
	unsigned char now_char, arr[10][10];
	int i, j, dest_row, dest_col, next_move, curr_row, curr_col;

	/* array initialization */
	for (i = 0; i < 10; i++) {
		for (j = 0; j < 10; j++) {
			arr[i][j] = '.';
		}
	}

	/* set random seed */
	srand((unsigned)time(NULL));

	/* character initialization */
	now_char = 'A';

	/* initializing random starting point with 'A'  */
	dest_row = rand() % 10;
	dest_col = rand() % 10;
	arr[dest_row][dest_col] = now_char;

	/* loop begins */
	for (;;) {

		/* save current position */
		curr_row = dest_row;
		curr_col = dest_col;

		/* decide next move randomly, for new destination */
		next_move = rand() % 4;

		/* switch - case statement begins, for changing destination according to next_move.
		* if the new destination is not valid, we continue.
		*/
		switch (next_move) {

			/* UP */
		case 0:
			if (dest_row == 0) {
				continue;
			}
			dest_row--;
			break;

			/* RIGHT */
		case 1:
			if (dest_col == 9) {
				continue;
			}
			dest_col++;
			break;

			/* DOWN */
		case 2:
			if (dest_row == 9) {
				continue;
			}
			dest_row++;
			break;

			/* LEFT */
		case 3:
			if (dest_col == 0) {
				continue;
			}
			dest_col--;
			break;
		}



		/* if the destination contains no character, simply write next char. */
		if (arr[dest_row][dest_col] == '.') {
			now_char++;
			arr[dest_row][dest_col] = now_char;
		}

		/* if the destination contains a character... */
		else if (arr[dest_row][dest_col] != '.') {

			/* if the destination contains a character, we must change destination!
			* if all 4 blocks around current position are occupied, this program will terminate. (no need for further trying)
			*/


			/* a series of if-statement begins :
			*	 1.is (above, left, below, right) space of current position valid?
			*	 2 and, is the space empty?
			*     ===> if both 1 and 2 are satisfied, then we must try further.
			*/

			/* was there empty space left to current position ? */
			if ((curr_row - 1) >= 0 && arr[curr_row - 1][curr_col] == '.') {
				/* if we can try further, we restore destination to current position and continue. */
				dest_row = curr_row;
				dest_col = curr_col;
				continue;
			}

			/* was there empty space left to current position ? */
			else if ((curr_col - 1) >= 0 && arr[curr_row][curr_col - 1] == '.') {
				/* if we can try further, we restore destination to current position and continue. */
				dest_row = curr_row;
				dest_col = curr_col;
				continue;
			}

			/* was there empty space below current position ? */
			else if ((curr_row + 1) < 10 && arr[curr_row + 1][curr_col] == '.') {
				/* if we can try further, we restore destination to current position and continue. */
				dest_row = curr_row;
				dest_col = curr_col;
				continue;
			}

			/* was there empty space right to current position ? */
			else if ((curr_col + 1) < 10 && arr[curr_row][curr_col + 1] == '.') {
				/* if we can try further, we restore destination to current position and continue. */
				dest_row = curr_row;
				dest_col = curr_col;
				continue;
			}
			else {
				printf("All four sides are block!\n");
				break;
			}
		}



		if (now_char == 'Z')
			break;


	}

	printf("Result is : \n");
	for (i = 0; i < 10; i++) {
		for (j = 0; j < 10; j++) {
			printf("%c ", arr[i][j]);
		}
		printf("\n");
	}

	return 0;
}