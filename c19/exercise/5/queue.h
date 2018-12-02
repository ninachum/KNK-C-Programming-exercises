#ifndef QUEUE_H
#define QUEUE_H

#include <stdbool.h> /* C99 only */
#define MAX_SIZE 100

typedef struct {
	int arr[MAX_SIZE];
	int insert_idx;
	int remove_idx;
	int num_items;
} Queue;
typedef int Item;

Queue *create(void);
void destroy(Queue *q);
void insert(Queue *q, Item i);
void remove(Queue *q);
Item first_item(Queue *q);
Item last_item(Queue *q);
bool is_empty(Queue *q);

#endif