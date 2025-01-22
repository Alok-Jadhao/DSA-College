#include <ctype.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "stack.h"

double eval_Postfix(const char *);

int main()
{
    char expression[100];
    printf("Enter expression: ");
    scanf("%s", expression);
    printf("The Answer is: %f", eval_Postfix(expression));
}

double eval_Postfix(const char *expression)
{
    struct Stack Stack;
    initStack(&Stack);
    for (int i = 0; expression[i] != '\0'; i++)
    {
        if (isdigit(expression[i]))
        {
            push(Stack, (double)(expression[i] - '0'));
        }
        else
        {
            double operand2 = pop(Stack);
            double operand1 = pop(Stack);

            switch (expression[i])
            {
            case '+':
                push(Stack, operand1 + operand2);
                break;
            case '-':
                push(Stack, operand1 - operand2);
                break;
            case '*':
                push(Stack, operand1 * operand2);
                break;
            case '/':
                if (operand2 == 0)
                {
                    printf("Error: Division by Zero\n");
                }
                else
                {
                    push(Stack, operand1 / operand2);
                }
                break;
            default:
                printf("Error: Invalid Operator\n");
                break;
            }
        }
    }
    return pop(Stack);
}