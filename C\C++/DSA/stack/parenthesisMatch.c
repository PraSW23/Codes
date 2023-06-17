#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <stdbool.h>

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
         printf("%c\n",s->arr[index--]);
    }
}

void pop(struct stack * s){
    
    if(s->top == -1){
        return;
    }
    else {
        s->arr[s->top--] = '0';
    }

}

void push(struct stack * s , char data){
    if(s->size == s->top+1){
        //printf("Stack Overflow! unable to push %d\n",data);
        return;
    }
    else s->arr[++s->top] = data;
}

bool paren(struct stack * s){
    int size = s->size;
    
    int i = 0;
    while(i != size){
    printf("%c\n",s->arr[i]);
        if(s->arr[i]=='('){
            if(s->top == s->size-1)
                return false;
            else
                push(s ,'(');
        }
        else if(s->arr[i] == ')'){
            if(s->top == -1)
                return false;
            else  
                pop(s);
        }
        i++;
    }
    if(s->top != -1)
        return false;
    else
        return true;
}


int main(){
struct stack *s = (struct stack *)malloc(sizeof(struct stack)) ;
printf("Enter number of nodes or size of stack : ");
//scanf("%d%*c", &s->size);

scanf("%d",&s->size);
CreateSTK(s);

    scanf("%s",s->arr);

if(paren(s)){
    printf("\nParenthesis Matched\n");
}else{
    printf("\nParenthesis Not Matched\n");
}

 return 0;
}