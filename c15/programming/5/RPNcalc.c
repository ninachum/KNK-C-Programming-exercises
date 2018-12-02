#include <stdbool.h> /* C99 only */
#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

double read_and_evaluate_expression(void);
void print_result(double result);

int main(void)
{
	for (;;) {

		make_empty();

		print_result(read_and_evaluate_expression());

	}

	return 0;
}

double read_and_evaluate_expression(void)
{
	double left_op, result, right_op;
	unsigned char ch;

	printf("Enter an RPN expression (zero to exit): ");
	for (;;) {
		scanf(" %c", &ch);

		if (ch == '0')
			exit(0);

		if (ch >= '1' && ch <= '9')
			push(ch - 48);
		else if (ch == '+' || ch == '-' || ch == '*' || ch == '/') {
			right_op = pop();
			left_op = pop();

			switch (ch) {
			case '+':
				result = left_op + right_op;
				break;
			case '-':
				result = left_op - right_op;
				break;
			case '*':
				result = left_op * right_op;
				break;
			case '/':
				result = left_op / right_op;
				break;
			}
			push(result);
		}
		else if (ch == '=')
			return pop();
	}
}

void print_result(double result)
{
	printf("Value of expression: %.2f\n", result);
}
