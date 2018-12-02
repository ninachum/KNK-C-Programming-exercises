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
	char name[2 * NAME_LEN];
	char last_name_temp[NAME_LEN + 1], first_name_temp[NAME_LEN + 1];
	char *newline_delete = name;

	printf("Enter your name: ");
	/* we've used scanf(), not fgets(), to skip white-spaces before && after the full name */
	scanf("%s %s", first_name_temp, last_name_temp);
	sprintf(name, "%s %s", first_name_temp, last_name_temp);
	
	reverse_name(name);

	printf("%s\n", name);

	return 0;
}
	
/* a name contains two 'chunks' is  expected. ex) kim hyunmin */
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


	