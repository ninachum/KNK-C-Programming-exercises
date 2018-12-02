#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
	FILE *fp;
	int i;

	if (argc <= 1) {
		printf("Usage : canopen foo.txt ... \n");
		exit(EXIT_FAILURE);
	}

	for (i = 1; i <= (argc - 1); i++) {
		fp = fopen(argv[i], "rb");

		if (fp == NULL) {
			printf("%s cannot be open.\n", argv[i]);
		}
		else {
			printf("%s can be open.\n", argv[i]);
			fclose(fp);
		}

	}

	return 0;
}