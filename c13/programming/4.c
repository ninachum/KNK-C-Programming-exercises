#include <stdio.h>

/* do not forget to add command-line arguments in 'project' menu. */
int main(int argc, char *argv[])
{
	int i = argc - 1;

	while (i > 0) {
		printf(" %s ", argv[i]);
		i--;
	}
	printf("\n");

	return 0;
}

