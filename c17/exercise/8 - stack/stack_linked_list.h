#ifndef STACK_LINKED_LIST_H
#define STACK_LINKED_LIST_H

#include <stdbool.h>


void make_empty(void);
bool is_empty(void);
bool push(int n);
int pop(void);
void stack_overflow(void);
void stack_underflow(void);


#endif