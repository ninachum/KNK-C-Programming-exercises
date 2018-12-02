/* a program that adds up its command-line arguments,
 * which are assumed to be integers.
 */

#include <stdlib.h>
#include <stdio.h>

int main(int argc, char *argv[])
{
	int sum = 0, i;
	
	for (i = 1; i < argc; i++)
		sum += atoi(argv[i]);

	printf("Total : %d\n", sum);

	return 0;

}

				