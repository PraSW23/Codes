#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node * next;
};

struct node * createLL(){
 int num, val;
 struct node * head, * ptr;
 printf("Enter number of nodes : ");
 scanf("%d",&num);
 printf("Enter data : ");

 for(int i=1; i<=num; i++){

 scanf("%d",& val);
 struct node * n = (struct node *)malloc(sizeof(struct node));
 n->data = val;
 n->next = NULL;

 if(i==1){
    head = n;
    ptr=n;
 }
 else {
    ptr->next = n;
    ptr=ptr->next;
 }

 }
 return head;
}

void LLtraversal(struct node * ptr){

    while(ptr!=NULL){
        printf("->%d",ptr->data);
        ptr=ptr->next;
    }
    printf("\n");
}

struct node * LLinsertion(struct node * head, int index , int val){
 
 struct node *ptr,* n = (struct node *)malloc(sizeof(struct node));
 int count=1;
 n->data = val;
 n->next = NULL;
 ptr = head;

 if(index==0){
  n->next = head;
  return n;
 }else{
 while(ptr!=NULL){
    if(index==count){
      n->next = ptr->next;
      ptr->next = n;
      return head;
    }
       ptr=ptr->next;
       count++;
 }
  printf("\nWARNING! INDEX IS OUT OF RANGE\n\n");
  return head;
 }

}

int main(){
 
 struct node * head;
  head = createLL();
  LLtraversal(head);
  
  int index, val;
  printf("Enter Value and index : ");
  scanf("%d %d",&val, &index);
  head = LLinsertion(head,index,val);
  LLtraversal(head);

    return 0;
}