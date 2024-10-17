#include<stdio.h>

void toh(int, char, char, char);

int main()
{
    int n;
    printf("Enter num of disks: ");
    scanf("%d",&n);

    printf("The sequence of moves involved in the Tower of Hanoi from Pole 'A' to 'C' are are:\n");
    toh(n,'A','C','B');
}

void toh(int n, char src, char dest, char aux){
    if(n == 1)  printf("Move disk 1 from ROD %c to ROD %c \n", src,dest);
    else{
        toh(n-1,src, aux, dest);
        printf("Move disk %d from ROD %c to ROD %c \n",n, src,dest);
        toh(n-1, aux, dest, src);
    }
}