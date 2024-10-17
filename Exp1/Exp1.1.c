//Experiment 1: Solving Tower of Hanoi using Recursion

#include<stdio.h>
#include<stdlib.h>

void toh(int, char, char,char);

int main(){
    printf("Enter the number of Disks : ");
    int n;
    scanf("%d",&n);
    printf("The Steps to move %d Disks from A to C is : \n",n);
    toh(n,'A','C','B');
}

void toh(int n, char src, char dest, char aux){
    if(n==1){
        printf("Move Disk 1 from %c to %c\n",src,dest);
        return;
    }
        toh(n-1,src,aux,dest);
        printf("Move Disk %d from %c to %c\n",n,src,dest);
        toh(n-1,aux,dest,src);
}



