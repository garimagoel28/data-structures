#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int data;
    struct Node *next;
} *top = NULL;
typedef struct Node Node;

void push(int x)
{
    Node *t;
    t = (Node *)malloc(sizeof(Node));
    if (t == NULL)
        printf("stack is full\n");
    else
    {
        t->data = x;
        t->next = top;
        top = t;
    }
}
int pop()
{
    Node *t;
    int x = -1;
    if (top == NULL)
        printf("Stack is Empty\n");
    else
    {
        t = top;

        top = top->next;
        x = t->data;
        free(t);
    }
    return x;
}
void Display()
{
    Node *p;
    p = top;
    while (p != NULL)
    {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
}

int main()
{
    push(10);
    push(20);
    push(30);
    Display();
    printf("%d\n", pop());
    Display();
    return 0;
}