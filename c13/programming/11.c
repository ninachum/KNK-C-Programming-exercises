#include <stdio.h>
#include <ctype.h>

#define LENGTH 100

double compute_average_word_length(const char *sentence);

int main(void)
{
	char sentence[LENGTH + 1];
	
	printf("Enter a sentence: ");
	/* sentence is supposed to end with '\n', and '\0' */
	fgets(sentence, sizeof(sentence), stdin);


	printf("%.2f\n", compute_average_word_length(sentence));
	return 0;
}

double compute_average_word_length(const char *sentence)
{
	double sum = 0;
	int divisor = 0;

	while (*sentence) {
		/* sentence is supposed to end with '\n', and '\0' */
		while (!isspace(*sentence)) {
			sum += 1;
			sentence++;
		}
		divisor += 1;
		sentence++;
	}

	return sum / divisor;
}