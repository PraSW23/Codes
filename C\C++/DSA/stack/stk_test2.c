#include<stdio.h>
#include<stdlib.h>


struct stack{
    int size;
    struct node * top; 
};

struct node{
    int data;
    struct node * next;
};

struct node * createList(int size){
    struct node * prev=NULL,*head=NULL;
    printf("Enter Data : ");
    for (int i = 0; i < size; i++)
    {   
        struct node * n = (struct node *)malloc(sizeof(struct node));
        n->next = NULL;
        
        scanf("%d",& n->data);
        head = n;

        if (i>0)
        {
            n->next = prev;
        }
        prev = n;
    }
    
    return head;
}

struct node * createSTK(struct stack * stk){

    stk->top = createList(stk->size);
    return stk->top;

}


void traverseSTK(struct node * top){
    
    while (top!=NULL)
    {
        printf("| %d |\n",top->data);
        top = top->next;
    }
    printf("\n");
    
}

int pop(struct stack * stk){
    if(stk->top==NULL){
        printf("Warning Stack Underflow or stack is Empty\n");
        return 0;
    }
    else{
        struct node * temp = stk->top->next;
        int data = stk->top->data;
        free(stk->top);
        stk->top = temp;
        stk->size--;
        return data;
    }
    

}

struct node * push(struct node * top ,int val){

    struct node * n = (struct node *)malloc(sizeof(struct node));
    n->data = val;
    n->next = top;
    top = n;
    return top;
}

int main(){
    struct stack * stk = (struct stack *)malloc(sizeof(struct stack));

    printf("Enter the size of Stack : ");
    scanf("%d",& stk->size);

    stk->top = createSTK(stk);

    traverseSTK(stk->top);
    stk->top = push(stk->top,50);
    traverseSTK(stk->top);

    printf("Popped value is %d \n", pop(stk));
    traverseSTK(stk->top);

    return 0;
}