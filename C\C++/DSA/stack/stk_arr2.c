#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

struct stack {
    int size;
    int * arr;
    int top;
};

void CreateSTK(struct stack * s){
    s->arr = (int *)malloc(sizeof(int)*s->size);
    s->top = -1;
}

void STKtraversal(struct stack * s){
    int index = s->top;
    while( index > -1){
         printf("%d\n",s->arr[index--]);
    }
}

int pop(struct stack * s){
    int val = s->arr[s->top];
    if(s->top==-1){
        printf("\nStack is empty! unable to pop\n");
        return val;
    }
    else {
        printf("\nPopping %d from top of stack\n", val);
        s->arr[s->top--] = 0;
    }
    return val;
}

void push(struct stack * s , int data){
    if(s->size == s->top+1){
        printf("Stack Overflow! unable to push %d\n",data);
        return;
    }
    else s->arr[++s->top] = data;
}

int main(){
struct stack s ;
 int num;
 printf("Enter number of nodes or size of stack : ");
 scanf("%d",&num);
 s.size = num;
 CreateSTK(&s);
push(&s,50);
push(&s,80);
push(&s,68);
push(&s,92);
STKtraversal(&s);
 int val = pop(&s);
 printf("\nPopping %d from top of stack ", val);
 STKtraversal(&s);
    return 0;
}