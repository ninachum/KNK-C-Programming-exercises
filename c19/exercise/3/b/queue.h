#ifndef QUEUE_H
#define QUEUE_H

#include <stdbool.h> /* C99 only */

void insert(int i);
void my_remove(void);
int first_item(void);
int last_item(void);
bool is_empty(void);

#endif