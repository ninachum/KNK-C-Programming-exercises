/* Copies a file */

#include <stdio.h>
#include <stdlib.h>

#define BUFFER_SIZE 512
typedef unsigned char BYTE;

int main(int argc, char *argv[])
{
	FILE *source_fp, *dest_fp;
	BYTE source_buffer[BUFFER_SIZE];
	int i;


	if (argc != 3) {
		fprintf(stderr, "usage: fcopy source dest\n");
		exit(EXIT_FAILURE);
	}

	if ((source_fp = fopen(argv[1], "rb")) == NULL) {
		fprintf(stderr, "Can't open %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	if ((dest_fp = fopen(argv[2], "wb")) == NULL) {
		fprintf(stderr, "Can't open %s\n", argv[2]);
		fclose(source_fp);
		exit(EXIT_FAILURE);
	}

	while ((i = fread(source_buffer, sizeof(BYTE), BUFFER_SIZE, source_fp)) > 0)
		fwrite(source_buffer, sizeof(BYTE), i, dest_fp);

	if (ferror(source_fp)) {
		fprintf(stderr, "READ ERROR \n");
		exit(EXIT_FAILURE);
	}

	if (ferror(dest_fp)) {
		fprintf(stderr, "WRITE ERROR \n");
		exit(EXIT_FAILURE);
	}

	fclose(source_fp);
	fclose(dest_fp);

	return 0;

}