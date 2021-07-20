// C program for conversion of infix to postfix with expressions having brackets and operators with right to left associativity

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node
{
    char data;
    struct node *next;
} *top = NULL;
typedef struct node node;

void push(char term)
{
    node *newNode = (node *)malloc(sizeof(node));
    if (newNode == NULL)
        printf("Stack is full\n");
    else
    {
        newNode->data = term;
        newNode->next = top;
        top = newNode;
    }
}

char pop()
{
    char x = '0';
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

char stackTop()
{
    if (top == NULL)
        printf("Stack is empty\n");
    else
        return top->data;
}

int isEmpty()
{
    return top == NULL ? 1 : 0;
}

int isOperand(char x)
{
    if (x == '+' || x == '-' || x == '*' || x == '/' || x == '^'|| x == ')'|| x == '(')
        return 0;
    else
        return 1;
}

int out_pre(char x)
{
    if (x == '+' || x == '-')
        return 1;
    else if (x == '*' || x == '/')
        return 3;
    else if (x == '^')
        return 6;
    else if (x == '(')
        return 7;
    else if (x == ')')
        return 0;
}

int in_pre(char x)
{
    if (x == '+' || x == '-')
        return 2;
    else if (x == '*' || x == '/')
        return 4;
    else if (x == '^')
        return 5;
    else if (x == '(')
        return 0;
}

char *inToPost(char *infix)
{
    char *postfix = (char *)malloc((strlen(infix) + 1) * sizeof(char *));
    int i = 0;
    int j = 0;
    while (infix[i] != '\0')
    {
        if (isOperand(infix[i]))
            postfix[j++] = infix[i++];
        else
        {
            if (top == NULL || out_pre(infix[i]) > in_pre(stackTop()))

                push(infix[i++]);

            else if(out_pre(infix[i]) == in_pre(stackTop()))
            {
                pop();
                i++;

            }
            else
                postfix[j++] = pop();

        }
    }

    while (!isEmpty())
    {
        postfix[j++] = pop();
    }
    postfix[j] = '\0';
    return postfix;
}

int main()
{
    char *infix = "((a+b)*c)-d^e^f";
    char *postfix = inToPost(infix);
    printf("\n%s", postfix);
    return 0;
}