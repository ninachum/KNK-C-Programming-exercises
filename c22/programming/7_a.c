#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define COUNTER 0
#define CONTENT 1

int main(int argc, char *argv[])
{
	int content_temp;
	char counter_and_content[2];
	char temp_file_name[FILENAME_MAX];
	FILE *source, *dest;

	if (argc != 2) {
		printf("Usage : compress_file original_file\n");
		exit(EXIT_FAILURE);
	}

	if ((source = fopen(argv[1], "rb")) == NULL) {
		printf("Can't open source file %s.\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	/* check length of (string + .rle + null-character) */
	if (strlen(argv[1]) + 4 + 1 <= FILENAME_MAX)
		sprintf(temp_file_name, "%s.rle", argv[1]);
	else {
		printf("File name is too long.\n");
		exit(EXIT_FAILURE);
	}

	if ((dest = fopen(temp_file_name, "wb")) == NULL) {
		printf("Can't create file %s.\n", temp_file_name);
		exit(EXIT_FAILURE);
	}

	/* initializing */
	if ((content_temp = getc(source)) != EOF) {
		counter_and_content[COUNTER] = 1;
		counter_and_content[CONTENT] = content_temp;
	}
	else {
		printf("Source file is empty.\n");
		exit(EXIT_FAILURE);
	}

	/* main loop */
	while ((content_temp = getc(source)) != EOF) {
		if (content_temp == counter_and_content[CONTENT])
			counter_and_content[COUNTER]++;
		else {
			putc(counter_and_content[COUNTER], dest);
			putc(counter_and_content[CONTENT], dest);
			counter_and_content[COUNTER] = 1;
			counter_and_content[CONTENT] = content_temp;
		}
	}

	/* if EOF is read, flush the data. */
	putc(counter_and_content[COUNTER], dest);
	putc(counter_and_content[CONTENT], dest);

	fclose(source), fclose(dest);

	return 0;
}