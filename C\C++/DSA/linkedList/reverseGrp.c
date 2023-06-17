#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *createLL(int n)
{
    int val;
    printf("Enter DATA : ");
    struct node *next = NULL, *head = NULL;
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &val);
        struct node *n = (struct node *)malloc(sizeof(struct node));
        n->data = val;
        n->next = NULL;
        if (i == 1)
        {
            head = n;
            next = n;
        }
        else
        {
            next->next = n;
            next = n;
        }
    }
    return head;
}

void LLtraversal(struct node *ptr)
{
    if (ptr == NULL)
    {
        printf("\n Linked List is Empty");
        return;
    }

    while (ptr != NULL)
    {
        printf("->%d", ptr->data);
        ptr = ptr->next;
    }
    printf("\n");
}

struct node * reverseGrp(struct node * head , int k){
    struct node * ptr = head->next->next , *prev = head->next, *temp = head , *str;

    head->next = NULL;
    int count=1, x=1;
  //  printf("\nReversing list\n");
    while(prev!=NULL && count<k){
        prev->next = head;
        head = prev;
        prev = ptr;
        if(ptr!=NULL)
        ptr = ptr->next;
        count++;
    }
    
      str = head;

    if(prev!=NULL){

        head = prev;
        temp->next = reverseGrp(head , k);
        
    }

   return str;
}



int main()
{
   int n,k;
   printf("Enter number of nodes : ");
   scanf("%d", &n);
   struct node *head = createLL(n);
   LLtraversal(head);
   
   printf("Enter value of k : ");
   scanf("%d",&k);
   head = reverseGrp(head,k);
   LLtraversal(head);

    return 0;
}