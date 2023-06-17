#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node * CreationLL(int n)
{
    struct node *head = NULL, *ptr = NULL;
    printf("Enter data : ");

    for (int i = 1; i <= n; i++)
    {
        int val;
        scanf("%d", &val);
        struct node *node = (struct node *)malloc(sizeof(struct node));
        if (i == 1)
        {
            head = node;
            ptr = node;
        }
        node->data = val;
        ptr->next = node;
        ptr = ptr->next;
        if (i == n)
        {
            node->next = head;
        }
    }
    return head;
}

void LLtraverse(struct node *head)
{
    struct node *ptr = head;
    if(head == NULL){
        printf("\nEMPTY list\n");
        return;
    }

    do
    {
        printf("->%d", ptr->data);
        ptr = ptr->next;
    } while (ptr != head);
    printf("\n");
}

struct node *inserionLL(struct node *head, int index, int val)
{
    struct node *ptr = head, *node = (struct node *)malloc(sizeof(struct node));
    node->data = val;
    int count = 1;
    
    while(1){              //we can also use do-while loop here (like doublyLL.c)     
     if(index==0){

        if(ptr->next==head){
            node->next = ptr->next;
            ptr->next = node;
            return node;
        }
     }
     else{

         if(index==count){
            node->next = ptr->next;
            ptr->next = node;
            return head;
         }

     }
        count++;
        ptr= ptr->next;
        if(ptr == head)
        break;
    }
 printf("\nERROR ! Invalid index \n");
 return head;
    
}

struct node *deletionLL(struct node *head, int index)
{
    struct node *ptr = head;
    int count = 1;
    if (index == 0)
    {
        while (1)
        {
            if (ptr->next == head)
            {
                ptr->next = ptr->next->next;
                free(head);
                return ptr->next;
            }
            ptr = ptr->next;
        }
    }
    else
    {
        while (1)
        {
            if (ptr == head && count>1)
            {
                break;
            }
            if (index == count)
            {
                struct node *temp = ptr->next;
                ptr->next = ptr->next->next;
                free(temp);
                return head;
            }
            count++;
            ptr = ptr->next;
            
        }
    }
    printf("\nERROR ! Invalid index \n");
    return head;
}

int main()
{
    int n, val, index;
    printf("Enter the number of nodes : ");
    scanf("%d", &n);

    struct node *head = CreationLL(n);
    LLtraverse(head);

    printf("\nEnter Value and index to insert : ");
    scanf("%d %d", &val, &index);
    head = inserionLL(head, index, val); // index modulation is used
    LLtraverse(head);

    printf("\nEnter index to delete : ");
    scanf("%d", &index);
    head = deletionLL(head, index); // index modulation is not used
    LLtraverse(head);
}