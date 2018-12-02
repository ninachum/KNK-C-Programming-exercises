/* Performs XOR encryption */

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

#define KEY '&'

int main(int argc, char *argv[])
{
	FILE *orig, *new;
	int orig_char, new_char;

	if (argc != 3) {
		printf("Usage : xor origfile newfile \n");
		exit(EXIT_FAILURE);
	}

	if ((orig = fopen(argv[1], "rb")) == NULL) {
		printf("Can't open the original file.\n");
		exit(EXIT_FAILURE);
	}

	if ((new = fopen(argv[2], "wb")) == NULL) {
		printf("Can't create the destination file.\n");
		exit(EXIT_FAILURE);
	}

	while ((orig_char = getc(orig)) != EOF) {
		new_char = orig_char ^ KEY;
		putc(new_char, new);
	}

	if (ferror(orig)) {
		printf("Read error occured.\n");
		exit(EXIT_FAILURE);
	}

	if (ferror(new)) {
		printf("Write error occured.\n");
		exit(EXIT_FAILURE);
	}

	fclose(orig);
	fclose(new);

	return 0;
}