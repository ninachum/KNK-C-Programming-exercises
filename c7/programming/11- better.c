/* program that takes a first name and last name entered by the user.
 * and it displays last name, a comma, and the first initial, followed by a period.
 */

#include <stdio.h>
#include <ctype.h>

int main(void)
{
	int a = 1;
	unsigned char Fname_initial, Lname;

	/* gets input. ex) Lloyd Fosdick. */
	printf("Enter a first and last name: ");

	/* skips spaces before first name */
	while((Fname_initial = getchar()) == ' ')
		;
	/* now, Fname_initial contains the initial letter of first name.
	 * CAUTION: DO NOT USE scanf("%c", &Fname_initial) INSTEAD OF THIS.
	 * scanf("%c", ...) DO NOT SKIP WHITE-SPACE CHARACTER.
	 */
	
	/* then, skips the rest of first name */
	while(getchar() != ' ')
		;

	/* skips the space between first name and last name */
	while((Lname = getchar()) == ' ')
		;

	/* now, Lname is the first character of last name.
	 * we'll print last name first.
	 * CAUTION : the condition (Lname != ' ' || Lname != '\n') IS NOT RIGHT THIS CASE!!
	 */

	/* if space or '\n' appears, it is the end of name. then, exit this loop. */
	while(Lname != ' ' && Lname != '\n') {

		/* prints only the first character of last name as upper-case. */
		if(a == 1) {
			putchar(toupper(Lname));
			a++;
		}
		/* prints the rest of last name. */
		else
			putchar(Lname);
		
		/* takes next character in Lname */
		Lname = getchar();
	}

	printf(", %c.\n", toupper(Fname_initial));

	return 0;
}
	
