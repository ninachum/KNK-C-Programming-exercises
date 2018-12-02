/* calculates the smallest, and the largest number out of input numbers.
 * LOGIC : divide 4 numbers into 2 groups, each group with two numbers.
 *		   then, compare two numbers within each group.
 *         and, compare winners / losers separately.
 *         finally, we have the smallest / the largest number.
 * TOTAL 4 IF STATEMENTS.
 */

#include <stdio.h> 

int main(void)
{
	int a, b, c, d, smallest, largest, win_1, win_2, lost_1, lost_2;

	printf("Enter four integers: ");
	scanf("%d %d %d %d", &a, &b, &c, &d);

	if(a > b)
	{
		win_1 = a;
		lost_1 = b;
	}
	else
	{
		win_1 = b;
		lost_1 = a;
	}

	if(c > d)
	{
		win_2 = c;
		lost_2 = d;
	}
	else
	{
		win_2 = d;
		lost_2 = c;
	}

	if(win_1 > win_2)
		largest = win_1;
	else
		largest = win_2;

	if(lost_1 > lost_2)
		smallest = lost_2;
	else
		smallest = lost_1;

	printf("Largest : %d\n", largest);
	printf("Smallest : %d\n", smallest);

	return 0;
}

