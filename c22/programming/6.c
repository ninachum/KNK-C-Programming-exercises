#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main(int argc, char *argv[])
{
	FILE *fp;
	int i, j;
	long total_length, offset = 0;
	char temp[10];

	if (argc != 2) {
		printf("Usage : view file.ext\n");
		exit(EXIT_FAILURE);
	}

	fp = fopen(argv[1], "rb");
	if (fp == NULL) {
		printf("cannot open file %s.\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	fseek(fp, 0, SEEK_END);
	total_length = ftell(fp);
	fseek(fp, 0, SEEK_SET);
	printf("Offset              Bytes              Characters\n"
		"------  -----------------------------  ----------\n");

	while (total_length > 0) {
		/* prints offset */
		printf("%6d  ", offset);
		offset += 10;

		/* prints each bytes read */
		for (i = 0; i < ((total_length < 10) ? total_length : 10); i++) {
			fscanf(fp, "%c", &temp[i]);
			if (ferror(fp)) {
				printf("read error : file %s.\n", argv[1]);
				exit(EXIT_FAILURE);
			}
			printf("%-3.2x", temp[i]);
		}

		/* if less than 10 bytes have read (due to end of file), print spaces instead of bytes */
		if (total_length < 10)
			for (j = total_length; j < 10; j++)
				printf("   ");
		putchar(' ');

		/* i indicates how many bytes was read last time. */
		for (j = 0; j < i; j++) {
			if (isprint(temp[j]))
				putchar(temp[j]);
			else
				putchar('.');
		}
		putchar('\n');

		total_length -= 10;

	}

	return 0;
}