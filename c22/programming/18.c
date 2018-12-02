#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX_INTEGERS 10000

int compare_integer(const void *p, const void *q);
int main(int argc, char *argv[])
{
	FILE *fp;
	int arr[MAX_INTEGERS], i;
	int max, min, median;

	if (argc != 2) {
		printf("Usage : maxminmed filename\n");
		exit(EXIT_FAILURE);
	}

	if ((fp = fopen(argv[1], "r")) == NULL) {
		printf("Can't open %s \n", argv[1]);
		exit(EXIT_FAILURE);
	}

	/* tests there's at leat an integer. */
	while ((i = getc(fp)) != EOF) {
		if (isdigit(i))
			break;
	}

	if (feof(fp)) {
		printf("There's no integer. \n");
		exit(EXIT_FAILURE);
	}
	/* end of the test */


	for (i = 0; i < MAX_INTEGERS; i++) {
		if (fscanf(fp, "%d", &arr[i]) != 1)
			break;
	}

	/* now i is the number of integers. */
	qsort(arr, i, sizeof(int), compare_integer);

	max = arr[i - 1], min = arr[0];
	if (i % 2 == 0) {
		i /= 2;
		median = (arr[i - 1] + arr[i]) / 2;
	}
	else {
		i /= 2;
		median = arr[i];
	}

	printf("max : %d\nmin : %d\nmedian : %d\n", max, min, median);

	fclose(fp);

	return 0;

}

int compare_integer(const void *p, const void *q)
{
	return (*((int *)p) - *((int *)q));
}