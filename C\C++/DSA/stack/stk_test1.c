#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
struct stack{
    int size;
    int top;
    int * arr;
};

struct stack * createSTK(int size){
 
 struct stack *s = (struct stack *)malloc(sizeof(struct stack));
 s->size = size;
 s->arr = (int *)malloc(sizeof(int)*s->size);
 s->top = -1;
 return s;
}

void traverseSTK(struct stack * s){
    
    if(s->top==-1){
        printf("Empty stack \n");
    }
    else {
        int i = s->top;
        while(i!=-1)
            printf("%d\n ",s->arr[i--]);
    }


}

void push(struct stack * s, int val){

    if(s->top < s->size-1){
        s->top++;
        s->arr[s->top] = val;
    }
    else printf("Stack overflow\n");

}

int pop(struct stack * s){

    if(s->top == -1){
        printf("Stack Underflow\n");
        return INT_MIN;
    }
    else{
    int val = s->arr[s->top];
    s->top--;
    return val;
    }
}


    int main(){
    int size;
    printf("Enter the size of stack : ");
    scanf("%d",&size);

    struct stack * s = createSTK(size);
    push(s,40);
    push(s,50);
    push(s,60);
    push(s,70);
    traverseSTK(s);

    printf("Popped value is : %d",pop(s)) ;
    printf("\n");
    traverseSTK(s);

    return 0;
    }