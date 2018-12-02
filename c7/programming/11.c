#include <stdio.h>
#include <ctype.h>

int main(void)
{
	int a = 1;
	char Fname_initial, Lname;

	/* gets input. ex) Lloyd Fosdick. */
	printf("Enter a first and last name: ");

	/* skips spaces before first name */
	while((Fname_initial = getchar()) == ' ')
		;
	/* now, Fname_initial contains the initial letter of first name.
	 * CAUTION: DO NOT USE scanf("%c", &Fname_initial) INSTEAD OF THIS.
	 * scanf("%c", ...) DO NOT SKIP WHITE-SPACE CHARACTER.
	 */
	
	/* skips the rest of first name */
	while(getchar() != ' ')
		;

	/* skips the space gap between first name and last name */
	while(1) {

		Lname = getchar();

		if(Lname != ' ')
			break;
	}

	/* now, Lname is the first character of last name.
	 * print last name first.
	 * CAUTION : the condition (Lname != ' ' || Lname != '\n') IS NOT RIGHT!!
	 */
	while(Lname != ' ' && Lname != '\n') {

		/* prints the first character of last name as upper-case. */
		if(a == 1)
			putchar(toupper(Lname));
		else
			putchar(Lname);
		a++;

		Lname = getchar();
		
		/* exit loop when the result of getchar() is '\n' or ' '(a space). */
	}

	printf(", %c\n", toupper(Fname_initial));

	return 0;
}
	
