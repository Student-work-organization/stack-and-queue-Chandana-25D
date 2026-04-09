#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

/* Global pointers for queue */
struct Node *front = NULL;
struct Node *rear  = NULL;


/* ENQUEUE: Add element at rear */
void enqueue(int data)
{
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));

    newNode->data = data;
    newNode->next = NULL;

    if (front == NULL && rear == NULL)
    {
        front = rear = newNode;
    }
    else
    {
        rear->next = newNode;
        rear = newNode;
    }

    printf("Enqueued item is %d\n", data);
}


/* FRONT: Return front element without removing */
int front_element()
{
    if (front == NULL)
    {
        printf("Queue is empty\n");
        return -1;
    }

    return front->data;
}


/* CHECK IF QUEUE IS EMPTY */
int is_empty()
{
    if (front == NULL)
        return 1;   // True
    else
        return 0;   // False
}


/* MAIN FUNCTION */
int main()
{
    enqueue(10);
    enqueue(20);
    enqueue(30);

    printf("Front element is %d\n", front_element());

    if (is_empty())
        printf("Queue is empty\n");
    else
        printf("Queue is not empty\n");

    return 0;
}