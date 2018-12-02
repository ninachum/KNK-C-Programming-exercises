/* Classifies a poker hand */

#include <stdbool.h> /* C99 only */
#include <stdio.h>
#include <stdlib.h>

#define NUM_RANKS 13
#define NUM_SUITS 4
#define NUM_CARDS 5


/* external variables */
bool straight, flush, four, three;
int pairs; /* can be 0, 1, or 2 */
int hand[NUM_CARDS][2];

 /* prototypes */

void read_cards(void);
void analyze_hand(void);
void print_result(void);

/****************************************************************************
 * main : Calls read_cards, analyze_hand, and print_result repeatedly.      *
 ****************************************************************************/

int main(void)
{
	for (;;) {
		read_cards();
		analyze_hand();
		print_result();
	}

	return 0;

}

/****************************************************************************
* read_cards: Reads the cards into the external variable hand;				*
*		      checks for bad cards and duplicate cards.						*
*****************************************************************************/

void read_cards(void)
{
	char ch, rank_ch, suit_ch;
	bool bad_card, duplicate_card;
	int cards_read = 0, i, j;
	int rank, suit;

	for (i = 0; i < NUM_CARDS; i++)
		for (j = 0; j < 2; j++)
			hand[i][j] = 0;

	while (cards_read < NUM_CARDS) {
		bad_card = false;
		duplicate_card = false;

		printf("Enter a card: ");

		rank_ch = getchar();
		switch (rank_ch) {
		case '0':			exit(EXIT_SUCCESS); break;
		case '2':			rank = 0; break;
		case '3':			rank = 1; break;
		case '4':			rank = 2; break;
		case '5':			rank = 3; break;
		case '6':			rank = 4; break;
		case '7':			rank = 5; break;
		case '8':			rank = 6; break;
		case '9':			rank = 7; break;
		case 't': case 'T': rank = 8; break;
		case 'j': case 'J': rank = 9; break;
		case 'q': case 'Q': rank = 10; break;
		case 'k': case 'K': rank = 11; break;
		case 'a': case 'A': rank = 12; break;
		default:			bad_card = true; break;
		}

		suit_ch = getchar();
		switch (suit_ch) {
		case 'c': case 'C': suit = 0; break;
		case 'd': case 'D': suit = 1; break;
		case 'h': case 'H': suit = 2; break;
		case 's': case 'S': suit = 3; break;
		default:			bad_card = true;
		}

		while ((ch = getchar()) != '\n') {
			if (ch != ' ') bad_card = true;
		}

		for (i = 0; i <= cards_read - 1; i++) {
			if (rank == hand[i][0] && suit == hand[i][1]) {
				duplicate_card = true;
				break;
			}
		}


		if (bad_card)
			printf("Bad card; ignored\n");
		else if (duplicate_card)
			printf("Duplicate card; ignored.\n");
		else {
			hand[cards_read][0] = rank;
			hand[cards_read][1] = suit;
			cards_read++;
		}
	}
}

/****************************************************************************
* analyze_hand: Determines whether the hand contains a straight, a flush,   *
*               four-of-a-kind, and/or three-of-a-kind; determines the      *
*				number of pairs; stores the results into the external       *
*				variables straight, flush, four, three, and pairs.          *
****************************************************************************/
void analyze_hand(void)
{
	int i, j, min;
	int num_consec = 0, rank_counter, last_num_consec;
	int next_number;

	straight = false;
	flush = false;
	four = false;
	three = false;
	pairs = 0;

	/* check for flush */
	for (i = 1; i < NUM_CARDS; i++) {
		if (hand[0][1] =! hand[i][1])
			break;
	}
	if (i == 5)
		flush = true;

	/* check for straight */
	min = hand[0][0];
	for (i = 1; i < NUM_CARDS; i++) {
		if (min > hand[i][0])
			min = hand[i][0];
	}
	for (i = 0; i < NUM_CARDS - 1; i++) {
		next_number = min++ + 1;
		last_num_consec = num_consec;
		for (j = 0; j < NUM_CARDS; j++) {
			if (hand[j][0] == next_number)
				num_consec++;
		}
		/* abort comparison if there's no difference. */
		if (last_num_consec == num_consec)
			break;		
	}
	if (num_consec == NUM_CARDS - 1) {
		straight = true;
		return;
	}

	/* check for four-of-a-kind, 3-of-a-kind, and pairs */
	for (i = 0; i < NUM_RANKS; i++) {
		rank_counter = 0;
		for (j = 0; j < NUM_CARDS; j++) {
			if (i == hand[j][0])
				rank_counter++;
		}
		if (rank_counter == 4) four = true;
		if (rank_counter == 3) three = true;
		if (rank_counter == 2) pairs++;
	}
}

/****************************************************************************
* print_result: Prints the classification of the hand, based on the values *
*               of the external variables straight, flsuh, four, three,    *
*				 and pairs.                                                 *
****************************************************************************/
void print_result(void)
{
	if (straight && flush)	 printf("Straight flush");
	else if (four)			 printf("Four of a kind");
	else if (three &&
		pairs == 1)			 printf("Full house");
	else if (flush)			 printf("Flush");
	else if (straight)		 printf("Straight");
	else if (three)			 printf("Three-of-a-kind");
	else if (pairs == 2)	 printf("Two pairs");
	else if (pairs == 1)	 printf("Pair");
	else					 printf("High card");

	printf("\n\n");
}
