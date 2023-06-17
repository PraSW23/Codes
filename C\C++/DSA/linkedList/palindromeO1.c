#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};
// Please also do with recurrsion available at GFG
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

struct node * reverse(struct node * head){
    

    if(head->next == NULL || head == NULL){
        return head;
    }
    struct node * ptr = head->next->next , *prev = head->next;
    head->next = NULL;
    while(prev!=NULL){
        prev->next = head;
        head = prev;
        prev = ptr;
        if(ptr!=NULL)
        ptr = ptr->next;
    }
    return head; 

}

int palindrome(struct node  * head){
    struct node * ptr1 = head , *ptr2 = head , *temp, *temp1 ;

    if(head->next==NULL)
    return 1;
    while(ptr1!=NULL){
        if(ptr1->next == NULL){
            ptr2 = ptr2->next;
            break;
        }
        ptr1 = ptr1->next->next;
        ptr2 = ptr2->next;
    }
    
    ptr1 = head;
    temp1 = reverse(ptr2);
    temp = temp1;
    while(temp1!=NULL){
        if(ptr1->data != temp1->data){
           temp = reverse(temp);
           return 0;
        }
        temp1 = temp1->next;
        ptr1 = ptr1->next;
    }
    temp = reverse(temp);
   return 1;
}

int main()
{
   int n,k;
   printf("Enter number of nodes : ");
   scanf("%d", &n);
   struct node *head = createLL(n);
   LLtraversal(head);
   if(palindrome(head)){
    printf("\nIs palindrome\n");
   }
   else{
    printf("\nIs not palindrome\n");
   }
    LLtraversal(head);
    return 0;
}