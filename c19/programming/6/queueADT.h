#ifndef QUEUEADT_H
#define QUEUEADT_H

#include <stdbool.h> /* C99 only */

typedef struct queue_type *Queue;
typedef int Item;

Queue create(int size);
void destroy(Queue q);
void insert(Queue q, Item i);
void my_remove(Queue q);
Item first_item(Queue q);
Item last_item(Queue q);
bool is_empty(Queue q);

#endif