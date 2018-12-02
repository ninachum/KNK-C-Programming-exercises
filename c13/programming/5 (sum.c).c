/* a program that adds up its command-line arguments,
 * which are assumed to be integers.
 */

#include <stdio.h>
#include <math.h>
#include <string.h>

int main(int argc, char *argv[])
{
	int sum = 0, i;
	char *outer;
	int weight;

	for (i = 1; i < argc; i++) {
		outer = &argv[i][0];
		weight = strlen(outer);

		while (*outer)
			/* do not forget *outer is 'char' type. */
			sum += (int) pow(10, (weight--) - 1) * ((*outer++) - '0');
	}

	printf("Total : %d\n", sum);

	return 0;

}

				