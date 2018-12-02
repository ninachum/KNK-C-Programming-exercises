#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define COUNTER 0
#define CONTENT 1
#define FILENAME_MAX 256

char *get_extension(char *str);

int main(int argc, char *argv[])
{
	FILE *cmpd_file, *new_file;
	char counter_and_content[2];
	int i, temp;
	char new_file_name[FILENAME_MAX];

	if (argc != 2) {
		printf("Usage : uncompress_file compressed-file \n");
		exit(EXIT_FAILURE);
	}

	/* checks if extension is "rle" */
	if (strncmp(get_extension(argv[1]), "rle", 3) != 0) {
		printf("Not a rle file. \n");
		exit(EXIT_FAILURE);
	}

	cmpd_file = fopen(argv[1], "rb");
	if (cmpd_file == NULL) {
		printf("Can't open %s.\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	if ((strlen(argv[1]) + 1) <= FILENAME_MAX)
		strncpy(new_file_name, argv[1], strlen(argv[1]) + 1); // 1 is for null-char
	else {
		printf("FILENAME TOO LONG \n");
		exit(EXIT_FAILURE);
	}

	new_file = fopen(new_file_name, "wb");
	if (new_file == NULL) {
		printf("Can't create %s.\n", new_file_name);
		exit(EXIT_FAILURE);
	}

	/* main loop */
	while ((temp = fread(counter_and_content, 2 * sizeof(char), 2, cmpd_file)) == 2) {
		for (i = 0; i < counter_and_content[COUNTER]; i++)
			putc(counter_and_content[CONTENT], new_file);
	}

	if (temp == 1) {
		printf("File is incomplete. \n");
		remove(new_file_name);
		exit(EXIT_FAILURE);
	}

	if (ferror(cmpd_file)) {
		printf("There was a read error. \n");
		exit(EXIT_FAILURE);
	}

	if (ferror(cmpd_file)) {
		printf("There was a write error. \n");
		exit(EXIT_FAILURE);
	}

	fclose(cmpd_file);
	fclose(new_file);

	return 0;

}


char *get_extension(char *str)
{
	char* temp = str + strlen(str); // temp is '\0' of string 'str' now.

	for (; temp >= str; temp--) {
		if (*temp == '.')
			return (temp + 1);
	}

	return NULL;
}