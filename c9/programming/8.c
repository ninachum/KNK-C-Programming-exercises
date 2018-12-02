/* a program that simulates the game of craps. */

#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <ctype.h>

#define TRUE 1
#define FALSE 0

int roll_dice(void);
int play_game(void);

int main(void)
{
	unsigned char play_again;
	int win, win_counter = 0, lose_counter = 0;

	do {
		win = play_game();
		
		if (win == TRUE)
			win_counter++;
		else
			lose_counter++;

		printf("\nPlay again? ");

		/* takes input from user(Y or N, case doesn't matter) */
		play_again = getchar();

		/* to delete '\n' in buffer */
		getchar();

		printf("\n");
	} while (toupper(play_again) == 'Y');

	printf("\nWins: %d      Losses: %d\n", win_counter, lose_counter);

	return 0;
}

int roll_dice(void)
{
	int die1, die2;
	srand((unsigned)time(NULL));
	die1 = rand() % 6 + 1;
	die2 = rand() % 6 + 1;

	return die1 + die2;
}

int play_game(void)
{
	int rolled_times = 0, sum, point = 0;

	for (;;) {
		sum = roll_dice();
		rolled_times++;

		printf("You rolled: %d\n", sum);

		if (rolled_times == 1) {
			switch (sum) {
			case 7: case 11:
				printf("You win!\n");
				return TRUE;
			case 2: case 3: case 12:
				printf("You lose!\n");
				return FALSE;
			default:
				point = sum;
				printf("Your point is %d.\n", point);
				break;
			}
		}
		else if (point == sum) {
			printf("You win!\n");
			return TRUE;
		}
		else if (point == 7) {
			printf("You lose!\n");
			return FALSE;
		}

		printf("type enter button to roll again.\n");
		getchar();
	}
}
