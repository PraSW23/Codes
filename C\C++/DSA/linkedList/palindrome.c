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

int palindrome(struct node  * head){
    struct node * ptr = head;
    int count=-1, i=0 , j =0;
    while(ptr!=NULL){
        if(ptr->next == NULL){
            j=1;
            break;
        }
        ptr = ptr->next->next;
        count++;
    }
    if(count == -1){
        return 1;
    }
    ptr = head;
    int arr[count+1];
    while(ptr!=NULL){

        if((count--)>(-1)){
            arr[i++] = ptr->data; 
        }
        else{
            if(arr[--i] != ptr->data){
                return 0;
            }
        }
      ptr = ptr->next;
      if(count==-1 && j==1){
        ptr = ptr->next;
        count--;
      }
    }

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
   
    return 0;
}