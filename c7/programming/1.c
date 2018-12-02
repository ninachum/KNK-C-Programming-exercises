/* prints a table of squares using a while statement */

#include <stdio.h>

int main(void)
{
	/* in 64-bit computer (mine),
	 * this program will cause overflow if n == 46341 (sqrt of 2,147,483,647 is 46,340.xxx). so int is 32-bit in this machine.
	 * if i and n are short int type, this program will cause overflow if n == 182 (sqrt of 32,767 is 181,xxx). so short is 16-bit in this machine.
	 * CONCLUSION : same integer bits as typical 64-bit machine.
	 * 
	 * EXCEPTION : long type is 32bit in this system. (check 5.c)
	 */

	short i, n;

	printf("This program prints a table of squares. \n");
	printf("Enter number of entries in table: ");
	scanf("%hd", &n);

	for(i = 1; i <= n; i++)
		printf("%10hd%10hd\n", i, i * i);

	return 0;
}