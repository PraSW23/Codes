#include<stdio.h>
#include<stdlib.h>

struct node
{
    struct node *next;
    int data;
};

struct node * createNode(){
    struct node *n = (struct node *)malloc(sizeof(struct node *));
    int data;
    n->next=NULL;
    printf("\nEnter Data : ");
    scanf("%d",&data);
    n->data = data;
    return n;
    
}


int main(){
struct node *head,*ptr;
int n,i;
printf("Enter number of nodes : ");
scanf("%d",&n);
head = createNode();
ptr = head;
for (int i = 1; i < n; i++)
{
    ptr->next = createNode();
    ptr=ptr->next;
}

printf("LL traversal");
ptr = head;
for (int i = 1; i <= n; i++)
{
    printf("\n%d",ptr->data);
    ptr=ptr->next;
}


  
return 0;
}
