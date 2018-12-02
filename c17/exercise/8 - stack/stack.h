#ifndef STACK_H
#define STACK_H
#include <stdbool.h>


#define STACK_SIZE 100

void make_empty(void);
bool is_empty(void);
bool is_full(void);
void push(double i);
double pop(void);
void stack_overflow(void);
void stack_underflow(void);

#endif