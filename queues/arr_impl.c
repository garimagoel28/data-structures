// C program for implementation of queue using array (here object of structure "queue" is used)

#include <stdio.h>
#include <stdlib.h>

struct queue
{
    int size;
    int *arr;
    int rear;
    int front;
} q1;

void create_queue()
{
    q1.size = 8;
    q1.arr = (int *)malloc(q1.size * sizeof(int));
    q1.rear = -1;
    q1.front = -1;
}

int isFull()
{
    return q1.rear == q1.size - 1 ? 1 : 0;
}

int isEmpty()
{
    return q1.rear == q1.front ? 1 : 0;
}

void enqueue(int x)
{
    if (isFull())
        printf("Queue is full\n");
    else
        q1.arr[++q1.rear] = x;
}

int dequeue()
{
    if (isEmpty())
    {
        printf("Queue is empty\n");
        return 0;
    }
    else
        return q1.arr[++q1.front];
}

void display()
{
    for (int i = q1.front + 1; i <= q1.rear; i++)
        printf("%d ", q1.arr[i]);
}

int main()
{
    create_queue();

    for (int i = 1; i <= 8; i++)
        enqueue(i);

    for (int i = 0; i < 3; i++)
        dequeue();

    display();
}
