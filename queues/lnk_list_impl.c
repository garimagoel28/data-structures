// C program for implementation of queue using linked list

#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
} *front = NULL, *rear = NULL;

typedef struct node node;

int isEmpty()
{
    return front == NULL ? 1 : 0;
}

void enqueue(int x)
{
    node *newNode = (node *)malloc(sizeof(node));
    if (newNode == NULL)
        printf("Queue is full\n");
    else
    {
        newNode->data = x;
        newNode->next = NULL;
        if (front == NULL)
        {
            front = newNode;
            rear = newNode;
        }
        else
        {
            rear->next = newNode;
            rear = newNode;
        }
    }
}

int dequeue()
{
    int x = -1;
    if (isEmpty())
        printf("Queue is empty\n");
    else
    {
        x = front->data;
        node *temp = front;
        front = front->next;
        free(temp);
    }
    return x;
}

void display()
{
    node *ptr = front;
    int count = 0;
    printf("\nQueue is:\n");
    while (ptr != rear->next)
    {
        count++;
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }
    printf("\nSize = %d\n\n", count);
}

int main()
{
    for(int i=10; i<=50; i+=10)
        enqueue(i);
    display();
    printf("Popped out node had value = %d\n", dequeue());
    display();
}