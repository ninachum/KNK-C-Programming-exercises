#include <stdio.h>

#define MAX_DIGITS 10

/* external variables */
const int segments[10][7] = { { 1, 1, 1, 1, 1, 1, 0 }, /* 0 */
						   	  { 0, 1, 1, 0, 0, 0, 0 }, /* 1 */
							  { 1, 1, 0, 1, 1, 0, 1 }, /* 2 */
							  { 1, 1, 1, 1, 0, 0, 1 }, /* 3 */
							  { 0, 1, 1, 0, 0, 1, 1 }, /* 4 */
							  { 1, 0, 1, 1, 0, 1, 1 }, /* 5 */
							  { 1, 0, 1, 1, 1, 1, 1 }, /* 6 */
							  { 1, 1, 1, 0, 0, 0, 0 }, /* 7 */
							  { 1, 1, 1, 1, 1, 1, 1 }, /* 8 */
							  { 1, 1, 1, 1, 0, 1, 1 }  /* 9 */ };

unsigned char digits[4][MAX_DIGITS * 4];

/* prototypes */
void clear_digits_array(void);
void process_digit(int digit, int position);
void print_digits_array(void);

int main(void)
{
	int counter = 0;
	unsigned char nowchar;

	clear_digits_array();

	printf("Enter a number: ");
	while ((nowchar = getchar()) != '\n' && counter < 10) {
		if ('0' <= nowchar && nowchar <= '9') {
			process_digit(nowchar - 48, counter);
			counter++;
		}
	}

	print_digits_array();

	return 0;

}

void clear_digits_array(void)
{
	int i, j;

	for (i = 0; i < 4; i++) {
		for (j = 0; j < MAX_DIGITS * 4; j++) {
			digits[i][j] = ' ';
		}
	}
}

void process_digit(int digit, int position)
{
	if (segments[digit][0] == 1)
		digits[1][position * 4 + 1] = '_';
	if (segments[digit][1] == 1)
		digits[2][position * 4 + 2] = '|';
	if (segments[digit][2] == 1)
		digits[3][position * 4 + 2] = '|';
	if (segments[digit][3] == 1)
		digits[3][position * 4 + 1] = '_';
	if (segments[digit][4] == 1)
		digits[3][position * 4] = '|';
	if (segments[digit][5] == 1)
		digits[2][position * 4] = '|';
	if (segments[digit][6] == 1)
		digits[2][position * 4 + 1] = '_';
}

void print_digits_array(void)
{
	int i, j;

	for (i = 0; i < 4; i++) {
		for (j = 0; j < MAX_DIGITS * 4; j++) {
			printf("%c", digits[i][j]);
		}
		printf("\n");
	}
}