#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main(int argc, char *argv[])
{
	FILE *fp = fopen(argv[1], "r");
	int temp;

	if (argc != 2) {
		printf("Usage : toupper example.txt\n");
		exit(EXIT_FAILURE);
	}

	if (fp == NULL) {
		printf("Error : cannot open %s.\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	while ((temp = getc(fp)) != EOF)
		fprintf(stdout, "%c", toupper(temp));
		// this one is better than fprintf(stdout, "%c", isalpha(temp) ? toupper(temp) : temp);

	if (ferror(fp)) {
		printf("Error : there was an error, reading %s.\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	fclose(fp);

	return 0;
}