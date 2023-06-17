#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *createLL()
{
    int val, n;
    printf("Enter number of nodes : ");
    scanf("%d", &n);
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

    while (ptr != NULL)
    {
        printf("->%d", ptr->data);
        ptr = ptr->next;
    }
    printf("\n");
}

int middleLL(struct node * head){
struct node * ptr1=head , *ptr2  =head;
 
 while (ptr2!=NULL)
 {
    if(ptr2->next==NULL){
        break;
    }
    ptr1=ptr1->next;
    ptr2=ptr2->next->next;
 }
 return ptr1->data;

}

int main()
{
    int index, val,mid;
    struct node *head = createLL();
    LLtraversal(head);

    mid = middleLL(head);
    printf("\nThe middle element of LL is : %d\n",mid);

    return 0;
}