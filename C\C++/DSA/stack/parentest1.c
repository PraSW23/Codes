#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

struct stack {
    int size;
    char * arr;
    int top;
};

void CreateSTK(struct stack * s){
    s->arr = (char *)malloc(sizeof(char)*s->size);
    s->top = -1;
}

void STKtraversal(struct stack * s){
    int index = s->top;
    while( index > -1){
         printf("%d\n",s->arr[index--]);
    }
}

void pop(struct stack * s){
   //. int val = s->arr[s->top];
    if(s->top==-1){
       // printf("\nStack is empty! unable to pop\n");
        return;
    }
    else {
       // printf("\nPopping %d from top of stack\n", val);
        s->top--;
    }
    return;
}

void push(struct stack * s , char data){
    if(s->size == s->top+1){
       //printf("Stack Overflow! unable to push %d\n",data);
        return;
    }
    else s->arr[++s->top] = data;
   // printf("\n->%c",s->arr[s->top]);
}


int is_paren(struct stack * stk,char * str ){
    
    for(int i=0;i<100;i++){
        
        char k = str[i];
        if(k==')'  || k==']' || k=='}'){
        if(stk->top == -1)
            return 0;
        else   
        if(k==')'){
              if(stk->arr[stk->top] == '(')
              pop(stk);
              else return 0;
        }
        else if(k==']'){
            if(stk->arr[stk->top] == '[')
              pop(stk);
              else return 0;
        }
        else if(k=='}'){
            if(stk->arr[stk->top] == '{')
              pop(stk);
              else return 0;
        }
        } 
        else if(k=='('  || k=='[' || k=='{'){
              push(stk,k);
        }
        
    }
    if(stk->top==-1)
    return 1;
    else return 0;
    
}

int main(){
struct stack *s = (struct stack *)malloc(sizeof(struct stack)) ;
char str[100];
//printf("Enter number of nodes or size of stack : ");
scanf("%s",&str);
//scanf("%d",&s->size);
s->size = 100;
CreateSTK(s);
if(is_paren(s,str)==1)
printf("\nMatched");
else printf("\nNot Matched");
//STKtraversal(s);
 
    return 0;
}