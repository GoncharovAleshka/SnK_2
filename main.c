#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "my_stack.h"
/*
3. Дана строка, состоящая из круглых, квадратных и фигурных скобок,
необходимо выполнить проверку является последовательность скобок правильной.
Входная строка с последовательностью скобок задается в файле, имя которого
является входным аргументом программы. Реализовать программу определяющую
правильность последовательности скобок с использованием структуры данных
в соответствии с вариантом задания:
а. стэк
*/
int main(int argc, char * argv[])
{
    char symbol;
    FILE *file;
	char *fname = argv[1];
    my_Stack *stack_for_work = create_Stack();

	file = fopen(fname,"r");

	if (file == NULL)
	{
		printf("Can not open file '%s'",fname);
		return 0;
	}

    while ((symbol = fgetc(file)) != EOF)
    {
        if ((symbol == '(') || (symbol == '{') || (symbol == '['))
        {
            push(stack_for_work, symbol);
            printf("\nPush to stack: '%c' \n",symbol);
        }
        else
        {
            if (!stack_empty(stack_for_work))
            {
                if ((symbol == ')') && (peek(stack_for_work) == '('))
                {
                    pop(stack_for_work);
                    printf("\nPop from stack: '%c' \n",symbol);
                }
                else if ((symbol == '}') && (peek(stack_for_work) == '{'))
                {
                    pop(stack_for_work);
                    printf("\nPop from stack: '%c' \n",symbol);
                }
                else if ((symbol == ']') && (peek(stack_for_work) == '['))
                {
                    pop(stack_for_work);
                    printf("\nPop from stack: '%c' \n",symbol);
                }
            }
            else
            {
                push(stack_for_work, symbol);
                printf("\nPush to stack: '%c' \n",symbol);
                break;
            }
        }
    }

    if (stack_empty(stack_for_work))
    {
        printf("\nIn file '%s' is correct sequence of brackets",fname);
    }
    else
    {
        printf("\nIn file '%s' is wrong sequence of brackets",fname);
    }

    if (fclose(file))
        printf("File close error.\n");

    delete_Stack(&stack_for_work);
    printf("\nProgramm is end.\n");
    return 0;
}
