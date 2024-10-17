#include<stdio.h>
#include<stdlib.h>

#define MAX 5  // Maximum size of the queue

// Function prototypes
void initialize();  // Function to initialize the queue
void insert();      // Function to enqueue (insert) an element
void delete();      // Function to dequeue (remove) an element
int top();          // Function to return the front element
void display();     // Function to display all elements in the queue

int front = -1, rear = -1;  // Initialize front and rear
int queue[MAX];         // Array to store the queue

int main()
{
    int choice;
    initialize();  // Initialize the queue at the start
    while(1)
    {
        // Display menu options
        printf("\nMain Menu\n");
        printf("1. Insert an element\n");
        printf("2. Delete an element\n");
        printf("3. Display the front element\n");
        printf("4. Display the queue\n");
        printf("5. Exit\n");

        printf("\nEnter your choice: ");
        scanf("%d", &choice);  // Get user choice

        switch(choice)
        {
            case 1:
                insert();  // Enqueue operation
                break;
            case 2:
                delete();  // Dequeue operation
                break;
            case 3:
                printf("\nFront element is: %d\n", top());  // Display front element
                break;
            case 4:
                display();  // Display all elements
                break;
            case 5:
                exit(0);  // Exit program
                break;
            default:
                printf("\nEnter valid choice\n");
        }
    }
    return 0;
}

// Function to initialize the queue
void initialize()
{
    front = -1;
    rear = -1;
    printf("\nQueue initialized\n");
}

// Function to insert an element into the queue (enqueue)
void insert()
{
    int item;
    if (rear == MAX - 1)
    {
        printf("\nOVERFLOW\n");
        return;
    }
    printf("\nEnter the element: ");
    scanf("%d", &item);

    if (front == -1 && rear == -1)
    {
        front = 0;
        rear = 0;
    }
    else
    {
        rear = rear + 1;
    }
    queue[rear] = item;
    printf("\nValue inserted\n");
}

// Function to delete an element from the queue (dequeue)
void delete()
{
    int item;
    if (front == -1 || front > rear)
    {
        printf("\nUNDERFLOW\n");
        return;
    }
    else
    {
        item = queue[front];
        if (front == rear)
        {
            front = -1;
            rear = -1;
        }
        else
        {
            front = front + 1;
        }
        printf("\nValue deleted: %d\n", item);
    }
}

// Function to return the front element of the queue
int top()
{
    if (front == -1 || front > rear)
    {
        printf("\nUNDERFLOW\n");
        exit(1);
    }
    return queue[front];
}

// Function to display all elements in the queue
void display()
{
    int i;
    if (rear == -1)
    {
        printf("\nEmpty queue\n");
    }
    else
    {
        printf("\nQueue elements:\n");
        for (i = front; i <= rear; i++)
        {
            printf("%d ", queue[i]);
        }
        printf("\n");
    }
}
