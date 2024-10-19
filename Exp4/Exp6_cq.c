/*
Experiment 6: Circular Queue Operations Using Arrays

Problem Statement:
Design, develop, and implement a menu-driven program in C for the following operations on a Circular Queue using arrays with a maximum size (MAX):
Insert an element onto the Circular Queue.
Delete an element from the Circular Queue.
Demonstrate overflow and underflow situations on the Circular Queue.
Display the status of the Circular Queue.
Exit the program.
*/

#include<stdio.h>
#include<stdlib.h>

#define MAX 10

int cq[MAX];

int front, rear;

void initialize();
int isEmpty();
int isFull();
void eq();
void dq();
void display();

int main(){
    int ch;
    printf("Enter your Choice : ");
    while(1){
        printf("\n**** MENU ****");
        printf("\n1. Insert\n2. Delete\n3. Display\n4. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &ch);

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
        
        default:
            printf("Enter correct option");
            break;
        }
        if(ch==4)   break;
    }
}

void initialize(){
    front = rear = -1;
}

int isEmpty(){
    return (front == -1);
}

int isFull(){
    return ((rear+1)%MAX)==front;
}

void eq(){
    if(isFull()){
        printf("Overflow!!");
        return;
    }
    printf("Enter item to eq");
    int item;
    scanf("%d",&item);
    if(front == -1 )    front = 0;
    rear=(rear+1)%MAX;
    cq[rear] = item;
    printf("\n%d is Enqueued\n",item);
}

void dq(){
    if(isEmpty())
    {
        printf("\nUnderflow!!\n");
        return;
    }
    int item;
    item = cq[front];
    if(front == rear)
    {
        front = rear = -1;
    }
    else
    front = (front+1)%MAX;
    printf("\n%d is delted\n",item);
}

void display()
{
    if(isEmpty())
    {
        printf("\nUnderflow!!\n");
        return;
    }
    int i = front;
    while(i != rear){  // Traverse the queue circularly
        printf("%d \t", cq[i]);
        i = (i + 1) % MAX;  // Move to the next element circularly
    }
    printf("%d \t", cq[rear]);  
}