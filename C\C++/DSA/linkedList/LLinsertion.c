#include<stdio.h>
#include<stdlib.h>

struct node {
    struct node *next;
    int data;
};

struct node* createNode(){
 struct node* n = (struct node*)malloc(sizeof(struct node*));
 printf("Enter Data : ");
  scanf("%d",&n->data); 
  n->next=NULL;
  return n;
}

void traversal(struct node* ptr1){
    printf("\nTraversal of nodes");

  while(ptr1!=NULL){
    printf("\n%d",ptr1->data);
    ptr1 = ptr1->next;
  }

}

struct node* insertion(int index,struct node *ptr,int val,int n){

struct node* head1 = (struct node*)malloc(sizeof(struct node*));
struct node *temp = ptr;
   if(index>n || index<0){
    printf("Invalid index\n");
   return ptr;
   }
    if(index==0){
       head1->data = val;
       head1->next = ptr;
       return head1;
    }
    if(index==n){
        
        for(int i=1;i<=n;i++){
            if(i==n){
                ptr->next = head1;
                head1->data = val;
                head1->next = NULL;
                return temp;
            }
            else ptr=ptr->next;  
        }
    }
    for(int i=0;i<index;i++){
     if(i==index-1){
        head1->next = ptr->next;
        ptr->next = head1;
        head1->data = val;
        return temp;
     }
     ptr=ptr->next;
    }
   
}

int main(){
 struct node *ptr,*head;
 int i,n,index,val;
 printf("Enter number of nodes : ");
 scanf("%d",&n);

 head = createNode();
 ptr = head;
 for(i=1;i<n;i++){

     ptr->next = createNode();
     ptr = ptr->next;

 }
  ptr = head;
  printf("Before insertion\n");
  traversal(ptr);

  printf("\nEnter index(0-(n-1)) where node to be insert : ");
  scanf("%d",&index);
  printf("\nEnter value to insert : ");
  scanf("%d",&val);
  ptr = insertion(index,ptr,val,n);

  printf("After insertion\n");
  traversal(ptr);

  return 0;
}