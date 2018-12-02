#include <stdio.h>
#include <stdlib.h>

#define BUFFER_SIZE 256

typedef unsigned char BYTE;

void print_result(int item_number, int month, int day, int year, float price);

int main(int argc, char *argv[])
{
	BYTE buffer[BUFFER_SIZE];
	FILE *fp;
	int item_number, month, day, year;
	float price;


	fp = fopen(argv[1], "r");
	if (fp == NULL) {
		printf("can't read the file.\n");
		exit(EXIT_FAILURE);
	}

	printf("Item               Unit               Purchase\n"
		   "                   Price              Date\n");
	while (fgets(buffer, BUFFER_SIZE, fp) != NULL) {
		if (sscanf(buffer, "%d , %f, %d / %d / %d", &item_number, &price, &month, &day, &year) != 5) {
			printf("this file is not complete.\n");
			exit(EXIT_FAILURE);
		}
		print_result(item_number, month, day, year, price);
	}

	if (ferror(fp)) {
		printf("Read error occurred\n");
		exit(EXIT_FAILURE);
	}
	
	return 0;
}

void print_result(int item_number, int month, int day, int year, float price)
{
	printf("%-19d" "$ " "%6.2f" "           " "%.2d/%.2d/%.4d" "\n"
		, item_number, price, month, day, year);
}