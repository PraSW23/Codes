#include<stdio.h>
#include<stdlib.h>

struct node {
    struct node* next;
    int data;
};

struct node* createNode(){

struct node* n1 = (struct node*)malloc(sizeof(struct node));
 printf("Enter data ");
 scanf("%d",&n1->data);
 n1->next=NULL;
 return n1;

}

void traversal(struct node* ptr1){
    printf("\nTraversal of nodes");

  while(ptr1!=NULL){
    printf("\n%d",ptr1->data);
    ptr1 = ptr1->next;
  }

}

int main(){

struct node* ptr,*head;
 int i,n;
printf("Enter number of nodes ");
scanf("%d",&n);

 head = createNode();
 ptr = head;
 for(i=1;i<n;i++){
    ptr->next=createNode();
    ptr=ptr->next;
 }
  ptr = head;

 traversal(head);
 
    return 0;
}