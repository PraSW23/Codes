#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int * arr , top = -1;

void CreateSTK(int num){
    arr = (int *)malloc(sizeof(int)*num);
    for(int i=0;i<num;i++){
      //  arr[i] = INT_MIN;
    }
}

void STKtraversal(int index){
    printf("\n");
    while(index>-1){
        if(arr[index] == 0)
         printf("|_______|\n");
        else
         printf("|___%d___|\n",arr[index]);
        index--;
    }
    printf("\n");
}

int pop(){
    int val = arr[top];
    arr[top--] = 0;
    return val;
}

void push(int data){
    arr[++top] = data;
}

int main(){
 
 int num;
 printf("Enter number of nodes or size of stack : ");
 scanf("%d",&num);
 CreateSTK(num);
push(50);
push(80);
push(68);
push(92);
STKtraversal(num-1);
 int val = pop();
 printf("\nPopping %d from top of stack ", val);
 STKtraversal(num-1);
    return 0;
}