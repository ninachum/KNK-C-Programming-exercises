/* do four fundamental arithmetic operations, based on an expression input
 * but, no space is allowed in expression.
 */

#include <stdio.h>

int main(void)
{
	char ch;

	float a, b, result;

	printf("Enter an expression: ");

	/* read first number */
	scanf("%f", &a);
	result = a;

	/* loop starts. check operator, and read second number, and evaluate the result. */
	for(;;) {

		/* saves operator in [char ch]. if ch is '\n',  exit loop  */
		if((ch = getchar()) == '\n')
			break;
	
		/* read second number */
		scanf("%f", &b);
	
		/* evaluate the result */
		switch(ch) {
			case '+':
				result += b;
				break;
			case '-':
				result -= b;
				break;
			case '*':
				result *= b;
				break;
			case '/':
				result /= b;
				break;
			default:
				continue;
		}
	}

	printf("result is %.1f\n", result);
	
	
	return 0;
}