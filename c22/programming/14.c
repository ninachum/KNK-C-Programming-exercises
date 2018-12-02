#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define CONTENTS_BUFFER_SIZE 4000

typedef unsigned char BYTE;

int main(void)
{
	FILE *source, *dest;
	int shift_amount, temp;
	BYTE file_name_buffer[FILENAME_MAX];
	/* functions in <stdio.h> perform buffering automatically when it seems advantageous. this is for practice. */
	BYTE contents_buffer[CONTENTS_BUFFER_SIZE];

	printf("Enter name of file to be encrypted : ");
	fgets(file_name_buffer, FILENAME_MAX, stdin);
	temp = strlen(file_name_buffer) - 1;
	if (file_name_buffer[temp] == '\n')
		file_name_buffer[temp] = '\0';
	if ((source = fopen(file_name_buffer, "r")) == NULL) {
		printf("Error : can't open %s \n", file_name_buffer);
		exit(EXIT_FAILURE);
	}

	if (setvbuf(source, contents_buffer, _IOFBF, CONTENTS_BUFFER_SIZE) != 0) {
		printf("Error : setting buffer failed.\n");
		exit(EXIT_FAILURE);
	}

	if (strlen(file_name_buffer) + strlen(".enc") + 1 > FILENAME_MAX) {
		printf("Error : file name too long \n");
		exit(EXIT_FAILURE);
	}
	strncat(file_name_buffer, ".enc", strlen(".enc"));
	if ((dest = fopen(file_name_buffer, "w")) == NULL) {
		printf("Error : can't open %s \n", file_name_buffer);
		exit(EXIT_FAILURE);
	}

	printf("Enter shift amount (1 - 25): ");
	scanf("%d", &shift_amount);

	while ((temp = getc(source)) != EOF) {
		if (('a' <= temp && temp <= 'z')) 
			temp = ((temp - 'a') + shift_amount) % 26 + 'a';			// character will "wrap around" if it exceeds 'Z'.
		
		else if ('A' <= temp && temp <= 'Z')
			temp = ((temp - 'A') + shift_amount) % 26 + 'A';

		putc(temp, dest);
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