/*In this experiment, we perform basic operations on a stack:

push: Adds an element to the top of the stack.
pop: Removes the topmost element from the stack.
peek (top): Displays the topmost element without removing it.
isEmpty: Checks if the stack is empty.
isFull: Checks if the stack is full.
*/

#include<stdio.h>
#include<stdlib.h>
#define MAX 10

int stack[MAX];
int top = -1;

void push(int);
int pop();
int peak();
int isEmpty();
int isFull();
void display();

int main(){
    int ch,item;
    printf("\nEnter the Operation you want to perform:\n");
    while(1){
        printf("\n1. Push");
        printf("\n2. Pop");
        printf("\n3. Peak");
        printf("\n4. Display");
        printf("\n5. Exit\n");
        scanf("%d",&ch);
        switch (ch) {
            case 1:
                printf("\nEnter item: ");
                scanf("%d",&item);
                push(item);
                break;
            case 2:
                item = pop();
                printf("\n% d Deleted\n",item);
                break;
            case 3:
                printf("\nPeak is %d", peak());
                break;
            case 4:
                display();
                break;
            default:
                printf("\nEnter Correct Choice");
                break;
        }
        if(ch==5)   break;
    }
}

int isEmpty(){
    if(top == -1)   return 1;
    return 0;
}

int isFull(){
    if(top == MAX-1)   return 1;
    return 0;
}

void push(int n){
    if(isFull()){
        printf("\nOverflow!!!\n");
        exit(0);
    }
    top++;
    stack[top] = n;
    printf("\n%d pushed\n",n);
}

int pop(){
    if(isEmpty()){
        printf("\nUnderflow!!!\n");
        exit(0);
    }
    int item = stack[top];
    top--;
    return item;
}

int peak(){
    if(isEmpty()){
        printf("\nUnderflow!!!\n");
        exit(0);
    }
    return stack[top];
}

void display(){
    if(isEmpty()){
        printf("\nUnderflow!!!\n");
        exit(0);
    }
    
    for(int i = top; i>=0;i--){
        printf("\n%d\n",stack[i]);
    }
}

