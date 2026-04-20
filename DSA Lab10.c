#include <stdio.h>
#include <stdlib.h>

/* Node structure */
struct Node {
    int data;
    struct Node* next;
};

/* Global top pointer */
struct Node* top = NULL;

/* Push operation */
void push(int data) 
{
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));

    new_node->data = data;
    new_node->next = top;
    top = new_node;
}

/* Pop operation */
int pop() 
{
    if (top == NULL) 
    {
        printf("Stack is empty\n");
        return -1;
    }

    struct Node* temp = top;
    int popped_value = temp->data;

    top = top->next;
    free(temp);

    return popped_value;
}

/* Peek operation */
int peek() 
{
    if (top == NULL) 
    {
        printf("Stack is empty\n");
        return -1;
    }

    return top->data;
}

/* Empty operation */
int empty() 
{
    if (top == NULL)
        return 1;   // True
    else
        return 0;   // False
}

/* Main function */
int main() 
{
    push(10);
    push(20);
    push(30);

    printf("Popped: %d\n", pop());
    printf("Top element: %d\n", peek());

    if (empty())
        printf("Stack is empty\n");
    else
        printf("Stack is not empty\n");

    return 0;
}