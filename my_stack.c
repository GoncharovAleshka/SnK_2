#include "my_stack.h"

//резервирует память под стек
my_Stack* create_Stack()
{
    my_Stack *out = NULL;
    out = malloc(sizeof(my_Stack));

    if (out == NULL)
    {
        exit(OUT_OF_MEMORY);
    }

    out->size = INIT_SIZE;
    out->data = malloc(out->size * sizeof(type_of_stack));

    if (out->data == NULL)
    {
        free(out);
        exit(OUT_OF_MEMORY);
    }

    out->top = 0;
    return out;
}

//освобождает память под стек
void delete_Stack(my_Stack **stack)
{
    free((*stack)->data);
    free(*stack);
    *stack = NULL;
}

//увеличиает размер стека
void resize(my_Stack *stack)
{
    stack->size += STACK_PLUS;
    stack->data = realloc(stack->data, stack->size + sizeof(type_of_stack));
    if (stack->data == NULL)
    {
        exit (STACK_OVERFLOW);
    }
}

//добавляет элемент к стеку
//при необходимости расширяет стек
void push(my_Stack *stack, type_of_stack data)
{
    if (stack->top >= stack->size)
    {
        resize(stack);
    }

    stack->data[stack->top] = data;
    stack->top++;
}

//освобождает элемент стека
void pop(my_Stack *stack)
{
    if (stack->top == 0)
    {
        exit(STACK_UNDERFLOW);
    }
    stack->top--;
}

//выдает верхний элемент стека
type_of_stack peek(const my_Stack *stack)
{
    if (stack->top <= 0)
    {
        exit(STACK_UNDERFLOW);
    }
    return stack->data[stack->top - 1];
}

//проверяет пуст ли стек
byte stack_empty(const my_Stack *stack)
{
    if (stack->top == 0)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

