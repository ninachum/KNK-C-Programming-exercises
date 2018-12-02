/* prompts for five quiz grade for each of five students.
 * then computes the total score and average score for each student, and the avg, highest, lowest.
*/

#include <stdio.h>

/* for future array size change */

/* how many rows ? */
#define NUM_OF_ROW (((int) (sizeof(sum) / sizeof(sum[0]))))

/* how many columns ? */
#define NUM_OF_COL (((int) (sizeof(sum) / sizeof(sum[0]))))


int main(void)
{
	int i, j, low, high;
	int arr[5][5] = { 0 }, sum[5] = { 0 }, highscore[5] = { 0 }, lowscore[5] = { 0 };
	float avg[5] = { 0 };

	/* take a row at a time. calculating sum and avg same time. */
	for (i = 0; i < NUM_OF_ROW; i++) {
		printf("Enter quiz 1 ~ 5 score for student %d: ", i + 1);

		for (j = 0; j < NUM_OF_COL; j++) {
			scanf(" %d", &arr[i][j]);
			sum[i] += arr[i][j];
		}

		/* int / int is int. use type cast (float). cast (float) will have effect on only sum[i]. */
		avg[i] = (float) sum[i] / NUM_OF_ROW;
	}

	/* calculate lowest, highest value for each student. */
	for (i = 0; i < NUM_OF_ROW; i++) {
		/* initialization */
		low = arr[i][0];
		high = arr[i][0];

		/* compare low, high (NUM_OF_COL - 1) times, respectively. */
		for (j = 1; j < NUM_OF_COL; j++) {
			if (low > arr[i][j])
				low = arr[i][j];
			if (high < arr[i][j])
				high = arr[i][j];
		}

		lowscore[i] = low;
		highscore[i] = high;
	}
	
	/* prints the result, with format. */
	printf("Student     Sum     Average     Highest     Lowest\n");
	for (i = 0; i < NUM_OF_ROW; i++) {
		printf("  %2d        %3d     %6.2f         %3d         %3d\n", i + 1, sum[i], avg[i], highscore[i], lowscore[i]);
	}



	return 0;

}