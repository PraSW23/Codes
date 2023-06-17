#include<stdio.h>
#include<stdlib.h>

struct node{
  int data;
  struct node * next; 

};

struct node * createLL(struct node * ptr){
    int val;
     printf("Enter Data : ");
     scanf("%d",&val);

    struct node * temp = (struct node *)malloc(sizeof(struct node));

    if(ptr!=NULL)
    ptr->next = temp;

    ptr=temp;
    ptr->next = NULL;
    ptr->data=val;

    return ptr;

}

void LLtraversal(struct node * ptr){

printf("Linked List Traversal \n");
  while(ptr!=NULL){
    printf("%d->",ptr->data);
    ptr=ptr->next;
  }
    printf("\n");
}

struct node * insertnode(struct node * head){
 int in=0,val,index;
 printf("Enter index : ");
 scanf("%d",&val);
 printf("Enter value : ");
 scanf("%d",&index);
 struct node * ptr;
 ptr = head;
 printf("\nptr=%d",ptr->data);
 struct node * n = (struct node *)malloc(sizeof(struct node));

  if(index == 0){
     n->data = val;
     n->next = head;
     return n;
  } else {
      while(head!=NULL){
        printf("\nhello");
        if(head->next==NULL){
            printf("in=%d\n",in);
            head->next = n;
            n->data = val;
            n->next = NULL;
            return ptr;
        }
        in++;
        head = head->next;
      }
         
       

  }


}




int main(){
 int n,i,data,index;
  printf("Enter number of nodes : ");
  scanf("%d",&n);
  
  struct node * ptr;
  ptr = NULL;
  struct node * head = ptr;

  for(i=1;i<=n;i++){
    ptr =  createLL(ptr);
    if(i==1){  
      head = ptr;
      }
  }

  LLtraversal(head);
  LLtraversal(head);
  printf("Insertion\n");
  head = insertnode(head);
  LLtraversal(head);

    return 0;
}