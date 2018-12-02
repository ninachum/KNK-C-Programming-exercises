#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
	FILE *fp;
	int i, temp;

	if (argc == 1) {
		printf("Usage : fcat f1.c f2.c ...\n");
		exit(EXIT_FAILURE);
	}


	for (i = 1; i <= (argc - 1); i++) {
		fp = fopen(argv[i], "r");
		if (fp == NULL) {
			printf("\nError : can't open %s.\n", argv[i]);
			exit(EXIT_FAILURE);
		}

		while ((temp = getc(fp)) != EOF) {
			putc(temp, stdout);
			if (ferror(fp)) {
				printf("\nError : there was an write error writing %s.\n", argv[i]);
				exit(EXIT_FAILURE);
			}

		}
		
		if (ferror(fp)) {
			printf("\nError : there was an read error writing %s.\n", argv[i]);
			exit(EXIT_FAILURE);
		}

		fclose(fp);
	}

	return 0;
}