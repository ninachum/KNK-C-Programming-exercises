/* Finds the largest and smallest elements in an array. */

#include <stdio.h>

#define N 10

void max_min(int a[], int n, int *max, int *min);

int main(void)
{
	int b[N], *p, big, small;

	printf("Enter %d numbers: ", N);
	for (p = b; p < b + N; p++)
		scanf("%d", p);

	max_min(b, N, &big, &small);

	printf("Largest: %d\n", big);
	printf("Smallest: %d\n", small);

	return 0;

}

void max_min(int a[], int n, int *max, int *min)
{
	int *pp;

	*max = *min = a[0];
	for (pp = a; pp < a + n; pp++) {
		if (*pp > *max)
			*max = *pp;
		else if (*pp < *min)
			*min = *pp;
	}
}