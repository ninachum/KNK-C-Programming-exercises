#include <stdbool.h> /* C99 only */
#include <stdio.h>
#include <stdlib.h>


#define STACK_SIZE 100

/* external variables */
double contents[STACK_SIZE];
int top = 0;


/* prototypes */
void make_empty(void);
bool is_empty(void);
bool is_full(void);
void push(double i);
double pop(void);
void stack_overflow(void);
void stack_underflow(void);

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

		if (ch == 'q')
			exit(0);

		if (ch >= '0' && ch <= '9')
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

void make_empty(void)
{
	top = 0;
}

bool is_empty(void)
{
	return top == 0;
}

bool is_full(void)
{
	return top == STACK_SIZE;
}

void push(double i)
{
	if(is_full())
		stack_overflow();
	else
		contents[top++] = i;
}

double pop(void)
{
	if (is_empty())
		stack_underflow();
	else
		return contents[--top];
}


void stack_overflow(void)
{
	printf("Expression is too complex\n");
	exit(0);
}
void stack_underflow(void)
{
	printf("Not enough operands in expression\n");
	exit(0);
}