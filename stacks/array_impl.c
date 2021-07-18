// C program for array implementation of stack

#include <stdio.h>
#include <stdlib.h>

struct stack
{
    int top;
    int size;
    int *arr;
};
typedef struct stack stack;

void push(stack *st, int data)
{
    if (st->top == st->size - 1)
        printf("Stack overflow!\n");
    else
    {
        st->arr[++st->top] = data;
        printf("%d inserted on top of stack\n", data);
    }
}
int pop(stack *st)
{
    if (st->top == -1)
    {
        printf("Stack underflow!\n");
        return 0;
    }
    else
    {
        printf("%d popped out of stack.\n",st->arr[st->top]);
        return st->arr[st->top--];
    }
        
}

void peek(stack st, int pos)
{
    if (st.top - pos + 1 < 0)
        printf("Invalid position!\n");
    else
        printf("Data present at position %d is %d.\n", pos, st.arr[st.top - pos + 1]);
}

void top(stack st)
{
    if (st.top < 0)
        printf("Stack is empty!\n");
    else
        printf("%d is present at top of stack.\n",st.arr[st.top]);
}

void printStack(stack st)
{
    printf("The data present in stack is:\n");
    for(int i=st.top; i>=0; i--)
        printf("%d ",st.arr[i]);
    printf("\n");
}

void isEmpty(stack st)
{
    if (st.top == -1)
        printf("Stack is empty.\n");
    else
        printf("Stack is not empty.\n");
}

void isFull(stack st)
{
    if (st.top == st.size - 1)
        printf("Stack is full.\n");
    else
        printf("Stack is not full.\n");
}

int main()
{
    stack st;
    st.size = 5;
    st.arr = (int*)malloc(st.size*sizeof(int));
    st.top = -1;
    push(&st, 1);
    push(&st, 2);
    push(&st, 3);
    push(&st, 5);
    pop(&st);
    push(&st, 4);
    peek(st,3);
    top(st);
    printStack(st);
    isEmpty(st);
    isFull(st);
}
