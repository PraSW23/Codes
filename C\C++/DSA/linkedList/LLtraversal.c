#include<stdio.h>
#include<stdlib.h>

struct node{
    struct node* next;
    int data;
};




int main(){
 struct node* ptr;
struct node* head = (struct node*)malloc(sizeof(struct node));
struct node* second = (struct node*)malloc(sizeof(struct node));
struct node* third = (struct node*)malloc(sizeof(struct node));
  ptr = head;
  head->data = 1;
  head->next = second;

  second->data = 2;
  second->next = third;

  third->data = 3;
  third->next = NULL;
  
  while(ptr!=NULL){

    printf("\n%d",ptr->data);
    ptr = ptr->next;


  }


return 0;

}