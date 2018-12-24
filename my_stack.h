#ifndef MY_STACK_H_INCLUDED
#define MY_STACK_H_INCLUDED

#include <stdlib.h>

#define OUT_OF_MEMORY 0xE0
#define STACK_OVERFLOW 0xE1
#define STACK_UNDERFLOW 0xE2

#define INIT_SIZE 10
#define STACK_PLUS 10

typedef unsigned char byte;
typedef char type_of_stack; 

typedef struct type_Stack {
    type_of_stack *data;
    int top;
    int size;
} my_Stack;

my_Stack* create_Stack();
void delete_Stack(my_Stack **stack);
void resize(my_Stack *stack);
void push(my_Stack *stack, type_of_stack data);
void pop(my_Stack *stack);
type_of_stack peek(const my_Stack *stack);
byte stack_empty(const my_Stack *stack);

#endif // MY_STACK_H_INCLUDED