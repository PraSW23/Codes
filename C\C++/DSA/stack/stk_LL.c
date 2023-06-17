#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

struct node {
    int data;
    struct node * next;
};

struct node * CreateSTK(int num){
    struct node * top = NULL;
    int data;
    for(int i = 0; i<num; i++){
        scanf("%d",&data);
        struct node * n = (struct node *)malloc(sizeof(struct node));
        n->data = data;
        n->next = top;
        top = n;
    }
return top;
}

void STKtraversal(struct node * ptr){
    printf("\n");
    while(ptr!=NULL){
        if(ptr->data == INT_MIN)
            printf("|_______|\n");
        else
        printf("|___%d___|\n",ptr->data);
        ptr=ptr->next;
    }
    printf("\n");
}

struct node * push(int data , struct node * top){

        struct node * n = (struct node *)malloc(sizeof(struct node));
        n->data = data;
        n->next = top;
        top = n;
        return top;
}

int pop(struct node * top){
    int k = top->data;
    top->data = INT_MIN;
    top = top->next;
    return k;

}

int main(){
 
 struct node * top;
 int num;
 printf("Enter number of nodes or size of stack : ");
 scanf("%d",&num);
 top = CreateSTK(num);
 STKtraversal(top);
 top = push(10 , top);
 STKtraversal(top);
 pop(top);
 STKtraversal(top);
    return 0;
}