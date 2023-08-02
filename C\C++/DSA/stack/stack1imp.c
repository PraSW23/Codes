#include <stdio.h>
#include <stdlib.h>

struct stack
{
    int *arr;
    int *top;
    int * top_next;
    int size;
};

int *createSTK(struct stack *s)
{
    if (s->size == 0)
    {
        printf("STACK is NULL or SIZE of stack is 0.\n");
        return NULL;
    }
    else
    {
        s->arr = (int *)malloc(sizeof(int) * s->size);
        if(s->size  > 0){
            s->top_next = & s->arr[0];
        }
        
        return NULL;
    }
}

void traverseSTK(struct stack *s)
{
    if (s->size == 0)
    {
        printf("Stack size is 0\n");
        return;
    }
    else if(s->top == NULL){
             printf("\nEmpty Stack\n");
         }
        else
        {
            int *tmp = &s->arr[s->size-1], n = s->size - 1;
            while (tmp != &s->arr[0])
            {
                printf("|_%d_|\n", *tmp);
                tmp = &s->arr[--n];
            }
            printf("|_%d_|\n", *tmp);
    }
}

int *push(int val, struct stack *s)
{
    if (s->top == &s->arr[s->size-1])
    {
        printf("\nStack Overflow ! Unable to push\n");
    }
    else
    {  
        * s->top_next = val;
        s->top = s->top_next;
        s->top_next +=1;
        
    }
    return s->top;
}

int pop(struct stack * s){
    int val = * s->top;
    * s->top = -1;
    s->top_next-=1;
    s->top-=1;
    return val;
    
}

int main()
{
    struct stack *s = (struct stack *)malloc(sizeof(struct stack));
    s->top = NULL;
    s->arr = NULL;
    printf("\nEnter the size of stack : ");
    scanf("%d", &s->size);
    s->top = createSTK(s);

    s->top = push(6, s);
    s->top = push(5, s);
    s->top = push(4, s);
    s->top = push(3, s);
    s->top = push(2, s);
    s->top = push(1, s);

    traverseSTK(s);
    printf("top = %d\n", pop(s));
    printf("top = %d\n", pop(s));
    
    traverseSTK(s);
}