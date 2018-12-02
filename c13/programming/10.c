/* program that takes a first name and last name entered by the user.
 * and it displays last name, a comma, and the first initial, followed by a period.
 */

#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define NAME_LEN 30

void reverse_name(char *name);

int main(void)
{
	char name[NAME_LEN + 1];
	char *newline_delete = name;

	printf("Enter your name: ");
	fgets(name, sizeof(name), stdin);

	while (*newline_delete != '\n')
		newline_delete++;
	*newline_delete = '\0';

	reverse_name(name);

	printf("%s\n", name);

	return 0;
}
	
void reverse_name(char *name)
{
	char *divide_ptr = name;
	char first_initial[2] = {toupper(*name)};
	char last_name[NAME_LEN + 1];

	while (*divide_ptr != ' ')
		divide_ptr++;
	*divide_ptr = '\0';

	strcpy(last_name, divide_ptr + 1);
	*last_name = toupper(*last_name);

	strcpy(name, last_name);
	strcat(name, ", ");
	strcat(name, first_initial);
	strcat(name, ".");
}


	