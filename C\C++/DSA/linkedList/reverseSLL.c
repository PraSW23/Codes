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

struct node * reverse(struct node * head){
    
    if(head->next == NULL || head == NULL){
        return head;
    }

    struct node * ptr = head->next->next , *prev = head->next;
    head->next = NULL;
    printf("\nReversing list\n");
    while(prev!=NULL){
        prev->next = head;
        head = prev;
        prev = ptr;
        if(ptr!=NULL)
        ptr = ptr->next;
    }

    return head; 

}

int main(){
 
 struct node * head;
  head = createLL();
  LLtraversal(head);
  
  head = reverse(head);
  LLtraversal(head);

    return 0;
}