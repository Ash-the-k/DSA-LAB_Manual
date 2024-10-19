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


#include <stdio.h>
#define MAX 5

int q[MAX], front = -1, rear = -1;

void cenqueue();
void cdequeue();
void disp();
int isFull();
int isEmpty();

void main() {
    int ch;
    do {
        printf("\n**** MENU ****");
        printf("\n1. Insert\n2. Delete\n3. Display\n4. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &ch);

        switch(ch) {
            case 1: cenqueue(); break;
            case 2: cdequeue(); break;
            case 3: disp(); break;
            case 4: printf("\nExiting...\n"); break;
            default: printf("\nInvalid choice");
        }
    } while(ch != 4);
}

int isFull() {
    return (rear + 1) % MAX == front;
}

int isEmpty() {
    return front == -1;
}

void cenqueue() {
    int item;
    
    if(isFull()) {
        printf("\nQueue Overflow");
    } else {
        printf("\nEnter the number to insert: ");
        scanf("%d", &item);

        if(front == -1) {
            front = 0;
        }
        rear = (rear + 1) % MAX;
        q[rear] = item;
        printf("\n%d is inserted in the queue", item);
    }
}

void cdequeue() {
    int item;

    if(isEmpty()) {
        printf("\nQueue Underflow");
    } else {
        item = q[front];
        printf("\n%d is deleted", item);

        if(front == rear) {
            front = -1;
            rear = -1;
        } else {
            front = (front + 1) % MAX;
        }
    }
}

void disp() {
    int i;

    if(isEmpty()) {
        printf("\nQueue is empty");
    } else {
        printf("\nQueue contains:\n");
        for(i = front; i <= rear; i = (i + 1) % MAX) {
            printf("%d\t", q[i]);
        }
    }
}
