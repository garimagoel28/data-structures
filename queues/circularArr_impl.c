// C program for implementation of queue using circular array

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
    q1.size = 15;
    q1.arr = (int *)malloc(q1.size * sizeof(int));
    q1.rear = 0;
    q1.front = 0;
}

int isFull()
{
    // Queue is full when (rear + 1) % size = front
    return (q1.rear + 1) % (q1.size) == q1.front ? 1 : 0;
}

int isEmpty()
{
    // Queue is empty when rear = front
    return q1.rear == q1.front ? 1 : 0;
}

void enqueue(int x)
{
    if (isFull())
        printf("Queue is full\n");
    else
    {
        q1.rear = (q1.rear + 1)%q1.size;
        q1.arr[q1.rear] = x;
    }
        
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
    int i = q1.front + 1;
    while (i != (q1.rear + 1) % q1.size)
    {
        printf("%d ", q1.arr[i]);
        i = (i + 1) % q1.size;
    }
}

int main()
{
    create_queue();

    for (int i = 1; i <= 14; i++)
        enqueue(i);

    for (int i = 0; i < 10; i++)
        dequeue();
    enqueue(15);
    enqueue(16);
    enqueue(17);
    display();
}
