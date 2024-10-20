/*
Experiment 4: Queue Operations Using Dynamic Memory Allocation

Problem Statement:
Design and develop a program to perform insert, delete, and display operations on a queue using dynamic memory allocation functions such as malloc(), calloc(), and free(). Implement the queue using a linked list structure, where memory for nodes is allocated at runtime. The program should provide a menu-driven interface that allows the user to perform the following operations:
    Insert an element into the queue.
    Delete an element from the queue.
    Display the elements of the queue.

*/

#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *front = NULL;
struct node *rear = NULL;

void eq();
void dq();
void display();

int main(){
    int ch;
    printf("\nMain Menu\n");
    while (1)
    {
        printf("\n1. Insert an element\n");
        printf("2. Delete an element\n");
        printf("3. Display the queue\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d",&ch);
        switch (ch)
        {
        case 1:
            eq();
            break;
        
        case 2:
            dq();
            break;
        
        case 3:
            display();
            break;
        
        case 4:
            exit(0);
            break;
        
        default: printf("Enter Correct choice: \n");
            break;
        }
    }
    

}

void eq()
{
    struct node *ptr;
    ptr = (struct node *) malloc(sizeof(struct node));
    if(ptr == NULL)
    {
        printf("\nOverflow!!!\n");
        return;
    }
    int item;
    printf("\nEnter item to eq: \n");
    scanf("%d",&item);
    ptr->data = item;
    ptr->next = NULL;

    if(front == NULL)
    {
        front = ptr;
        rear = ptr;
    }
    else{
        rear->next = ptr;
        rear = ptr;
    }
}

void dq()
{
    struct node *ptr;
    if(front == NULL)
    {
        printf("\nUNDERFLOW!!!\n");
        return;
    }

    ptr = front;
    if(front == rear)   {
        front = rear = NULL;
    }
    else
    front = front->next;
    free(ptr);

}

void display(){
    if(front == NULL)
    {
        printf("\nUNDERFLOW!!!\n");
        return;
    }

    struct node *ptr;
    printf("\n");
    for(ptr = front; ptr != NULL; ptr = ptr->next)
    {
        printf("%d \t",ptr->data);
    }
}