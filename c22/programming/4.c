#include <stdio.h>
#include <stdlib.h>

int count_chars(FILE *fp);
int count_words(FILE *fp);
int count_lines(FILE *fp);

int main(int argc, char *argv[])
{
	FILE *fp = fopen(argv[1], "r");
	char cmd;

	if (argc != 2) {
		printf("Usage : count filename.txt\n");
		exit(EXIT_FAILURE);
	}

	if (fp == NULL) {
		printf("\nCan't open %s.\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	printf("\n1 : count characters"
		"\n2 : count words"
		"\n3 : count lines"
		"\ninput : ");
	scanf(" %1c", &cmd);

	switch (cmd) {
	case '1':
		printf("\nnumber of characters : %d\n", count_chars(fp));
		break;
	case '2':
		printf("\nnumber of words : %d\n", count_words(fp));
		break;
	case '3':
		printf("\nnumber of lines : %d\n", count_lines(fp));
		break;
	default:
		printf("No such command.\n");
		break;
	}

	return 0;
}

int count_chars(FILE *fp)
{
	int temp, result = 0;

	while ((temp = getc(fp)) != EOF)
		result++;

	if (ferror(fp)) {
		printf("\nRead error.\n");
		exit(EXIT_FAILURE);
	}

	return result;

}

int count_words(FILE *fp)
{
	int temp, result = 0;

	while ((temp = fscanf(fp, "%*s")) != EOF)
		result++;

	if (ferror(fp)) {
		printf("\nRead error.\n");
		exit(EXIT_FAILURE);
	}

	return result;
}

int count_lines(FILE *fp)
{
	int temp, result = 0;

	while ((temp = fscanf(fp, "%*[^\n]")) != EOF) {
		/* consume the '\n'. */
		getc(fp);
		result++;
	}

	if (ferror(fp)) {
		printf("\nRead error.\n");
		exit(EXIT_FAILURE);
	}

	return result;
}
