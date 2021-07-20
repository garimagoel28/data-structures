#include <stdlib.h>
#include <stdio.h>

struct node
{
    char data;
    struct node *next;
} *top = NULL;

typedef struct node node;

void push(char data)
{
    node *newNode;
    newNode = (node *)malloc(sizeof(node));
    if (newNode == NULL)
        printf("Stack is full\n");
    else
    {
        newNode->data = data;
        newNode->next = top;
        top = newNode;
    }
}

char pop()
{
    char x = '0';
    if (top == NULL)
        printf("Stack is empty\n");
    else
    {
        node *temp;
        temp = top;
        top = top->next;
        x = temp->data;
        free(temp);
    }
    return x;
}

int isMatchingPair(char a, char b)
{
    if (a == '(' && b == ')')
        return 1;
    else if (a == '[' && b == ']')
        return 1;
    else if (a == '{' && b == '}')
        return 1;
    else
        return 0;
}

int isBalanced(char *exp)
{
    for (int i = 0; exp[i] != '\0'; i++)
    {
        if (exp[i] == '{' || exp[i] == '(' || exp[i] == '[')
            push(exp[i]);
        else if (exp[i] == '}' || exp[i] == ')' || exp[i] == ']')
        {
            if (top == NULL)
                return 0;
            else
            {
                char opening = pop();
                char closing = exp[i];
                if (!isMatchingPair(opening, closing))
                    return 0;
            }
        }
    }
    return top == NULL ? 1 : 0;
}

int main()
{
    char *exp = "{(})";
    printf("%d ", isBalanced(exp));
}