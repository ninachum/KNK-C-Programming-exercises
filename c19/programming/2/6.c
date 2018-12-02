#include <stdbool.h> /* C99 only */
#include <stdio.h>
#include <stdlib.h>
#include "stackADT2.h" /* I've modified this to use double types as Item. */

#define STACK_SIZE 100

/* prototypes */
double read_and_evaluate_expression(void);
void print_result(double result);

int main(void)
{
	for (;;) 
		print_result(read_and_evaluate_expression());
	
	return 0;
}

double read_and_evaluate_expression(void)
{
	Stack s;
	s = create(STACK_SIZE);
	double left_op, result, right_op;
	unsigned char ch;

	printf("Enter an RPN expression (q to exit): ");
	for (;;) {
		scanf(" %c", &ch);

		if (ch == 'q')
			exit(0);

		if (ch >= '0' && ch <= '9')
			push(s, ch - 48);
		else if (ch == '+' || ch == '-' || ch == '*' || ch == '/') {
			right_op = pop(s);
			left_op = pop(s);

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
			push(s, result);
		}
		else if (ch == '=')
			return pop(s);
	}
	destroy(s);
}

void print_result(double result)
{
	printf("Value of expression: %.2f\n", result);
}

