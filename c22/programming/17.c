/*
	reads a series of phone numbers from a file and displays them in a standard format.
*/

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main(int argc, char *argv[])
{
	int phone_number[3];
	int temp, i;
	FILE *fp;

	if (argc != 2) {
		printf("Usage : display filename\n");
		exit(EXIT_FAILURE);
	}

	if ((fp = fopen(argv[1], "r")) == NULL) {
		printf("Can't open %s \n", argv[1]);
		exit(EXIT_FAILURE);
	}

	/*
		ABOUT fscanf(fp, "%[^0123456789] %d %[^0123456789] %d %[^0123456789] %d" ....);
			this function will fail if phonebook.txt starts with a digit.
			it is because there's no match for %[^0123456789], which is matching failure.
			so fscanf returns 0. (incicates no variable is assigned a value.)
	*/

	/* i is an index. it indicates where to store a number fragment. */
	i = 0;
	while ((temp = getc(fp)) != EOF) {
		if (!isdigit(temp))
			continue;
		else {
			/* if a character just read is digit, push back the character to stream, to read whole number. */
			ungetc(temp, fp);

			/* when index is 0 or 1, read three numbers. when 2, read four numbers. */
			if (i <= 1)
				fscanf(fp, "%3d", &phone_number[i++]);
			else
				fscanf(fp, "%4d", &phone_number[i++]);

			/* when a complete phone number is read, print it and set index to 0. */
			if (i >= 3) {
				printf("(%.3d) %.3d-%.4d\n", phone_number[0], phone_number[1], phone_number[2]);
				i = 0;
			}
		}
	}		

	/* if there's an incomplete phone number, index will indicate 1 or 2. */
	if (i != 0) {
		printf("Incomplete phone number detected. \n");
		exit(EXIT_FAILURE);
	}

	if (ferror(fp)) {
		printf("READ ERROR. \n");
		exit(EXIT_FAILURE);
	}

	fclose(fp);

	return 0;
}