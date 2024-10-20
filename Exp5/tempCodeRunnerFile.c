/*
Problem Statement:
Design, develop, and implement a menu-driven program in C for the following operations on a Priority Queue using arrays with a maximum size (MAX):
    Insert an element into the Priority Queue.
    Delete an element from the Priority Queue.
    Peek at the elements in the Priority Queue.
    Exit the program.
*/

#include<stdlib.h>
#include<stdio.h>

#define MAX 10

int pq[MAX];
int front;
int rear;

void eq();
void dq();
void display();
void check(int);
void create();
void peak();

int main(){
    printf("Select choice\n");
    int ch;
    create();
    while (1)
    {
        printf("\n1 - Insert an element into queue");
        printf("\n2 - Delete an element from queue");
        printf("\n3 - Display queue elements");
        printf("\n4 - Exit");
        printf("\nEnter your choice : ");
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
            peak();
            break;
        case 4:
            display();
            break;
        
        default:    printf("Enter correct Choice:\n");
            break;
        }
        if(ch == 5) break;
    }   
}

void create()
{
    front = rear = -1;
}

void eq(){
    if(rear == MAX-1)
    {
        printf("\nOVERFLOW!!");
        return;
    }
    int item;
    printf("\nEnter item to eq: \n");
    scanf("%d",&item);
    if(front == -1)
    {
        front = rear = 0;
        pq[rear] = item;
    }
    else{
        check(item);
    }
}

void check(int n)
{
    for(int i = front; i<=rear; i++)
    {
        if(n > pq[i])
        {
            for(int j = rear; j>=i;j--)
            {
                pq[j+1]=pq[j];
            }
            pq[i] = n;
            rear++;
            return;
        }
    }
    pq[++rear] = n;
}


void dq()
{
    if(front == -1)
    {
        printf("UNDERFLOW!!!");
        return;
    }
    int item;
    printf("\nEnter element to Delete: ");
    scanf("%d",&item);

    for(int i = front; i<=rear; i++){
        if(pq[i]==item){
            for(;i<rear;i++){
                pq[i]=pq[i+1];
            }
            printf("\n%d deleted\n",item);
            rear--;
            if(rear == -1)  front = -1;
            return;
        }
    }
    printf("\n%d not found\n",item);
}

void display()
{
    if(front == -1)
    {
        printf("UNDERFLOW!!!");
        return;
    }

    for(int i = front; i<=rear; i++)
    {
        printf("%d\t",pq[i]);

    }
    printf("\n");
}

void peak(){
    if(front == -1)
    {
        printf("UNDERFLOW!!!");
        return;
    }
    printf("\nPeak: %d\n",pq[front]);

}