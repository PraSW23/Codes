#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int * arr;

int CreateSTK(int num){
    arr = (int *)malloc(sizeof(int)*num);
    int i;
    
    for(i=0;i<num;i++){
        int data;
        scanf("%d", &data);
        arr[i] = data;  
    }
    return --i;
}

void STKtraversal(int index){
    printf("\n");
    while(index>-1){
        if(arr[index] == INT_MIN)
        printf("|_______|\n");
        else
        printf("|___%d___|\n",arr[index]);
        index--;
    }
    printf("\n");
}

int pop(int top){
    int val = arr[top];
    arr[top--] = INT_MIN;
    return val;
}

int push(int data , int top){
    arr[++top] = data;
    return top;
}

int main(){
 
 int num , top;
 printf("Enter number of nodes or size of stack : ");
 scanf("%d",&num);
 top = CreateSTK(num);
 STKtraversal(top);
 
 top = push(50 , top);
 STKtraversal(top);

 int val = pop(top);
 printf("\nPopping %d from top of stack ", val);
 STKtraversal(top);

 
    return 0;
}