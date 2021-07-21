// C program for evaluation of postfix expression

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node
{
    int data;
    struct node *next;
} *top = NULL;
typedef struct node node;

void push(int data)
{
    node *newNode = (node *)malloc(sizeof(node));
    if (newNode == NULL)
        printf("Stack is full\n");
    else
    {
        newNode->data = data;
        newNode->next = top;
        top = newNode;
    }
}

int pop()
{
    int x = 0;
    if (top == NULL)
        printf("Stack is empty");
    else
    {
        x = top->data;
        node *temp = top;
        top = top->next;
        free(temp);
    }
    return x;
}

int isOperand(char x)
{
    if (x == '+' || x == '-' || x == '*' || x == '/')
        return 0;
    else
        return 1;
}

int postfix_eval(char* postfix)
{
    int x1, x2;
    for(int i=0; postfix[i]!='\0'; i++)
    {
        if(isOperand(postfix[i]))
            push(postfix[i]-'0');
        else
        {
            x2 = pop();
            x1 = pop();
            switch(postfix[i])
            {
                case '+':
                    push(x1 + x2);
                    break;
                case '-':
                    push(x1 - x2);
                    break;
                case '*':
                    push(x1 * x2);
                    break;
                case '/':
                    push(x1 / x2);
                    break;
            }
        }
    }
    return pop();
}

int main()
{
    char *postfix = "35*62/+4-";
    printf("%d", postfix_eval(postfix));
    return 0;
}