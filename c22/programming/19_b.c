/*
In Windows, the end-line marker is a carriage-return character('\x0d') immediately followed by a line-feed character('\x0a').
In UNIX, a single line-feed character.

This program converts a UNIX text file to a Windows text file.
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main(int argc, char *argv[])
{
	FILE *source, *dest;
	int curr;

	if (argc != 3) {
		printf("Usage : convert file1 file2 \n");
		exit(EXIT_FAILURE);
	}

	/* open two files in binary mode (to access end-line marker without automatic translation to '\0') */
	if ((source = fopen(argv[1], "rb")) == NULL) {
		printf("Can't open %s \n", argv[1]);
		exit(EXIT_FAILURE);
	}

	if ((dest = fopen(argv[2], "wb")) == NULL) {
		printf("Can't open %s \n", argv[2]);
		exit(EXIT_FAILURE);
	}

	/* when there's an '\x0d', write it and an additional '\x0a'. */
	while ((curr = getc(source)) != EOF) {
		putc(curr, dest);
		if (curr == '\x0d')
			putc('\x0a', dest);
	}

	if (ferror(source)) {
		printf("Read error \n");
		exit(EXIT_FAILURE);
	}

	if (ferror(dest)) {
		printf("Write error \n");
		exit(EXIT_FAILURE);
	}

	fclose(source), fclose(dest);

	return 0;
}