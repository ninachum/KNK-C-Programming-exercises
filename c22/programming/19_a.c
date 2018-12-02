/*
In Windows, the end-line marker is a carriage-return character('\x0d') immediately followed by a line-feed character('\x0a').
In UNIX, a single line-feed character.

This program converts a Windows text file to a UNIX text file.
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main(int argc, char *argv[])
{
	FILE *source, *dest;
	int next, curr;

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

	/* when there's an '\x0d', peeks next character. if it is '\x0a', replace the two characters with a single '\x0a'. */
	while ((curr = getc(source)) != EOF) {
		if (curr == '\x0d') {
			next = getc(source);
			if (next == '\x0a')
				putc('\x0d', dest);
			else {
				ungetc(next, source);
				putc(curr, dest);
			}
		}
		else
			putc(curr, dest);
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