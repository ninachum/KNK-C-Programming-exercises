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

void read_expression(char expression[STACK_SIZE]);
double evaluate_expression(char *expression);
void print_result(double result);

int main(void)
{
	char expression[STACK_SIZE];

	for (;;) {

		make_empty();
		read_expression(expression);
		print_result(evaluate_expression(expression));

	}

	return 0;
}

void read_expression(char expression[STACK_SIZE])
{
	printf("Enter an RPN expression (zero to exit): ");
	fgets(expression, STACK_SIZE, stdin);
}

double evaluate_expression(char *expression)
{
	double left_op, result, right_op;
	
	for (;;) {
		/* input ends with '\n' or '\0', by fgets(). */
		if (*expression == '\n' || *expression == '\0') {
			printf("There's no '='.\n");
			exit(0);
		}
		else if (*expression == '0')
			exit(0);
		else if (*expression >= '1' && *expression <= '9')
			push(*expression - 48);
		else if (*expression == '+' || *expression == '-' || *expression == '*' || *expression == '/') {
			right_op = pop();
			left_op = pop();

			switch (*expression) {
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
		else if (*expression == '=')
			return pop();

		expression++;
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
	if (is_full())
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