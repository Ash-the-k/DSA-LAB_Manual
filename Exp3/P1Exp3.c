/*
 Problem Statement : Design and develop a program to perform the following operations on a Queue data structure :

 enqueue() : Adds an element to the end (rear) of the queue.
 dequeue() : Removes an element from the front of the queue.
 top() : Returns the first element in the queue without removing it.
 initialize() : Creates an empty queue.
 display() : Displays all elements currently in the queue.
 */

#include<stdio.h>
#include<stdlib.h>

#define MAX 10

int queue[MAX];
int front;
int rear;

void eq();
void dq();
int top();
void initialize();
void display();

int main(){
    int ch,item;
    initialize();
    while(1){
        printf("\nEnter your choice\n");
        printf("\n1. Enqueue");
        printf("\n2. Dequeue");
        printf("\n3. Top");
        printf("\n4. Display");
        printf("\n5. Exit\n");

        scanf("%d",&ch);
        switch (ch) {
            case 1:
                eq();
                break;
            case 2:
                dq();
                break;
            case 3:
                item = top();
                printf("Topmost Item is : %d",item);
                break;
            case 4:
                display();
                break;
            default:
                printf("\nEnter correct Choice!\n");
                break;
        }
        
        if(ch==5)   break;
    }
}

void initialize(){
    front = rear = -1;
}

void eq(){
    if(rear == MAX-1){
        printf("Overflow!!!");
        return;
    }
    printf("\nEnter item to Enqueue: \n");
    int item;
    scanf("%d",&item);
    if(front == -1) front = 0;
    rear++;
    queue[rear] = item;
    printf("\n%d is enqued\n",item);
}

void dq(){
    int item;
    if(front == -1 && rear == -1){
        printf("Underflow!!");
        return;
    }
    item = queue[front];
    if(front == rear){
        front = rear = -1;
    }
    else{
        front++;
    }
    printf("\n%d is delted\n",item);
}

int top(){
    int item;
    if(front == -1 && rear == -1){
        printf("Underflow!!");
        exit(0);
    }
    return queue[front];
}

void display(){
    if(front == -1 && rear == -1){
        printf("Underflow!!");
        exit(0);
    }
    
    for(int i = front; i<=rear; i++){
        printf("%d \t",queue[i]);
    }
}
