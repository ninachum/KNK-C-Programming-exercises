/* calculates (+, -, *, /) on two fractions*/

#include <stdio.h>

int main(void)
{
	char command;
	int nume1, denom1, nume2, denom2, result_nume, result_denom;

	printf("Command (+, -, *, /): ");
	scanf("%c", &command);

	switch(command) {
		case '+':
			printf("You've chosen +. Enter two fractions to add, separated by a blank.\n");
			scanf("%d / %d %d / %d", &nume1, &denom1, &nume2, &denom2);

			result_nume = nume1 * denom1 + nume2 * denom2;
			result_denom = denom1 * denom2;
			printf("Result is %d/%d.\n", result_nume, result_denom);
			break;
		
		case '-':
			printf("You've chosen -. Enter two fractions to subtract, separated by a blank.\n");
			scanf("%d / %d %d / %d", &nume1, &denom1, &nume2, &denom2);

			result_nume = nume1 * denom1 - nume2 * denom2;
			result_denom = denom1 * denom2;
			printf("Result is %d/%d.\n", result_nume, result_denom);
			break;

		case '*':
			printf("You've chosen *. Enter two fractions to multiply, separated by a blank.\n");
			scanf("%d / %d %d / %d", &nume1, &denom1, &nume2, &denom2);

			result_nume = nume1 * nume2;
			result_denom = denom1 * denom2;
			printf("Result is %d/%d.\n", result_nume, result_denom);
			break;

		case '/':
			printf("You've chosen /. Enter two fractions to divide, separated by a blank.\n");
			scanf("%d / %d %d / %d", &nume1, &denom1, &nume2, &denom2);

			result_nume = nume1 * denom2;
			result_denom = denom1 * nume1;
			printf("Result is %d/%d.\n", result_nume, result_denom);
			break;

	}

	return 0;
}