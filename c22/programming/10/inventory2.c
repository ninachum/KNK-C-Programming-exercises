/* Maintains a parts database (linked list version) */

#include <stdio.h>
#include <stdlib.h>
#include "readline.h"
#include <stdbool.h>
#include <string.h>

#define NAME_LEN 25
#define FILE_NAME_BUFFER_SIZE 256

struct part {
	int number;
	char name[NAME_LEN + 1];
	int on_hand;
	struct part *next;
};

struct part *inventory = NULL; /* points to first part */

struct part *find_part(int number);
void insert(void);
void search(void);
void update(void);
void print(void);
void dump(void);
void restore(void);

/*
 * main: Prompts the user to enter an operation code.
 *		 then calls a function to perform the requested
 *		 action. Repeats until the user enters the
 *		 command 'q'. Prints an error message if the user
 *		 enters an illegal code.
 */

int main(void)
{
	char code;

	for (;;) {
		printf("Enter operation code: ");
		scanf(" %c", &code);
		while (getchar() != '\n') /* skips to end of line */
			;
		switch (code) {
		case 'i': insert();
				  break;
		case 's': search();
				  break;
		case 'u': update();
				  break;
		case 'p': print();
				  break;
		case 'd': dump();
				  break;
		case 'r': restore();
				  break;
		case 'q': return 0;

		default:  printf("Illegal code\n");
		}
		printf("\n");
	}

	return 0;
}

/*
 * find_part: Looks up a part number in the inventory
 *			  list. Returns a pointer to the node
 *			  containing the part number; if the part
 *            number is not found, returns NULL.
 */
struct part *find_part(int number)
{
	struct part *p;

	for (p = inventory;
	  	 p != NULL && p->number != number;
		 p = p->next)
		;
	if (p != NULL && p->number == number)
		return p;
	return NULL;
}

/*
 * insert: Prompts the user for information about a new
 *		   part and then inserts the part into the
 *		   inventory list; the list remains sorted by part number.
 *         Prints an error message and returns
 *		   prematurely if the part already exists or 
 *		   space could not be allocated for the part.
 */
void insert(void)
{
	struct part *cur, *prev, *new_node;

	new_node = malloc(sizeof(struct part));
	if (new_node == NULL) {
		printf("Database is full, can't add more parts.\n");
		return;
	}

	printf("Enter part number: ");
	scanf("%d", &new_node->number);

	for (cur = inventory, prev = NULL;
		cur != NULL && new_node->number > cur->number;
		prev = cur, cur = cur->next)
		;
	if (cur != NULL && new_node->number == cur->number) {
		printf("Part already exists.\n");
		free(new_node);
		return;
	}

	printf("Enter part name: ");
	read_line(new_node->name, NAME_LEN);
	printf("Enter quantity on hand: ");
	scanf("%d", &new_node->on_hand);

	new_node->next = cur;
	if (prev == NULL)
		inventory = new_node;
	else
		prev->next = new_node;
}

/*
 * search: Prompts the user to enter a part number, then
 *		   looks up the part in the database. If the part
 *		   exists, prints the name and quantity on hand;
 *		   if not, prints an error meesage.
 */
void search(void)
{
	int number;
	struct part *p;

	printf("Enter part number: ");
	scanf("%d", &number);
	p = find_part(number);
	if (p != NULL) {
		printf("Part name: %s\n", p->name);
		printf("Quantity on hand: %d\n", p->on_hand);
	}
	else
		printf("Part not found.\n");
}

/*
 * update: Prompts the user to enter a part number.
 *		   Prints an error meesage if the part doesn't
 *		   exist; otherwise, prompts the user to enter
 *		   change in quantity on hand and updates the
 *		   database.
 */
void update(void)
{
	int number, change;
	struct part *p;

	printf("Enter part number: ");
	scanf("%d", &number);
	p = find_part(number);
	if (p != NULL) {
		printf("Enter change in quantity on hand: ");
		scanf("%d", &change);
		p->on_hand += change;
	}
	else
		printf("Part not found.\n");
}

/*
 * print: Prints a listing of all parts in the database.
 *		  showing the part number, part name, and
 *		  quantity on hand. Parts numbers will appear in
 *        ascending order.
 */
void print(void)
{
	struct part *p;


	printf("Part Number   Part Name                  "
		   "Quantity on Hand\n");
	for (p = inventory; p != NULL; p = p->next)
		printf("%7d       %-25s%11d\n", p->number,
			   p->name, p->on_hand);
}

void dump(void)
{
	struct part *curr;
	FILE *dump_file;
	char name_buffer[FILE_NAME_BUFFER_SIZE];

	printf("Enter name of output file: ");
	read_line(name_buffer, FILE_NAME_BUFFER_SIZE - 1);
	dump_file = fopen(name_buffer, "wb");
	if (dump_file == NULL) {
		printf("Dump Failed.\n");
		exit(EXIT_FAILURE);
	}

	if (inventory == NULL) {
		printf("Empty list.\n");
		exit(EXIT_FAILURE);
	}

	for (curr = inventory; curr != NULL; curr = curr->next)
		/* BE CAREFUL : [[ sizeof(struct part) - sizeof(struct part *) ]] is valid because
		 *  			'next' member is last member of struct part.
		 */
		fwrite(curr, sizeof(struct part) - sizeof(struct part *), 1, dump_file);

	if (ferror(dump_file)) {
		printf("write error during dump.\n");
		exit(EXIT_FAILURE);
	}

	/* without fclose(), contents will not be written to disk. */
	fclose(dump_file);

}

void restore(void)
{
	struct part *curr, *prev, *next_node;
	struct part temp;
	FILE *dump_file;
	char name_buffer[FILE_NAME_BUFFER_SIZE];
	bool is_first = true;


	printf("Enter name of input file: ");
	read_line(name_buffer, FILE_NAME_BUFFER_SIZE - 1);
	dump_file = fopen(name_buffer, "rb");
	if (dump_file == NULL) {
		printf("can't read %s.\n", name_buffer);
		exit(EXIT_FAILURE);
	}

	/* free used memories before loading data from file. */
	for (curr = inventory; curr != NULL; curr = next_node) {
		next_node = curr->next;
		free(curr);
	}

	/* BE CAREFUL : [[ sizeof(struct part) - sizeof(struct part *) ]] is valid because
	 *  			'next' member is last member of struct part.
	 */
	while (fread(&temp, sizeof(struct part) - sizeof(struct part *), 1, dump_file) == 1) {
		curr = malloc(sizeof(struct part));
		if (curr == NULL) {
			printf("reconstruction failed : malloc result is NULL.\n");
			exit(EXIT_FAILURE);
		}

		memcpy(curr, &temp, sizeof(struct part) - sizeof(struct part *));
		curr->next = NULL;

		if (is_first) {
			inventory = curr;
			is_first = false;
		}
		else
			prev->next = curr;
		prev = curr;
	}

	if (ferror(dump_file)) {
		printf("read error during restore.\n");
		exit(EXIT_FAILURE);
	}

	fclose(dump_file);
}
