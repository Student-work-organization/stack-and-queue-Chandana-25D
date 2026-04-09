#include <stdio.h>
#include <stdlib.h>

/* Queue structure */
struct Queue {
    int *arr;
    int front;
    int rear;
    int capacity;
};

/* Create Queue */
void initQueue(struct Queue *q, int size)
{
    q->capacity = size;
    q->front = -1;
    q->rear = -1;
    q->arr = (int*)malloc(size * sizeof(int));
}

/* Check if queue is empty */
int is_empty(struct Queue *q)
{
    return (q->front == -1);
}

/* Enqueue operation */
void enqueue(struct Queue *q, int data)
{
    if ((q->rear + 1) % q->capacity == q->front)
    {
        printf("Queue Overflow\n");
        return;
    }

    if (q->front == -1)
        q->front = 0;

    q->rear = (q->rear + 1) % q->capacity;
    q->arr[q->rear] = data;

    printf("Inserted %d\n", data);
}

/* Dequeue operation */
int dequeue(struct Queue *q)
{
    if (is_empty(q))
    {
        printf("Queue Underflow\n");
        return -1;
    }

    int data = q->arr[q->front];

    if (q->front == q->rear)
    {
        q->front = q->rear = -1;
    }
    else
    {
        q->front = (q->front + 1) % q->capacity;
    }

    return data;
}

/* Front operation */
int front_element(struct Queue *q)
{
    if (is_empty(q))
    {
        printf("Queue is empty\n");
        return -1;
    }

    return q->arr[q->front];
}

/* Main function */
int main()
{
    struct Queue q;
    initQueue(&q, 5);

    enqueue(&q, 10);
    enqueue(&q, 20);
    enqueue(&q, 30);

    printf("Front element: %d\n", front_element(&q));

    printf("Deleted element: %d\n", dequeue(&q));

    if (is_empty(&q))
        printf("Queue is empty\n");
    else
        printf("Queue is not empty\n");

    return 0;
}