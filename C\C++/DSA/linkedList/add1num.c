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
    struct node * ptr = head->next->next , *prev = head->next;

    head->next = NULL;
  //  printf("\nReversing list\n");
    while(prev!=NULL){
        prev->next = head;
        head = prev;
        prev = ptr;
        if(ptr!=NULL)
        ptr = ptr->next;
    }
    return head; 

}

struct node *add1(struct node *head)
{
    struct node *ptr = head , *ptr2;

    head = reverse(head);
    ptr2 = head;
    int carry = 0, num, x;
    printf("Enter number to add to linked list : ");
    scanf("%d",&x);

    while(ptr2!=NULL){

        if(ptr2==head){
          num = ptr2->data + x;
          ptr2->data = num%10;
          carry = num/10;


        }else {
            num = ptr2->data + carry;
            ptr2->data = num%10;
            carry = num/10;

            if(ptr2->next == NULL && carry!=0){
                struct node * n = (struct node *)malloc(sizeof(struct node));
                n->data = carry%10;
                carry = carry/10;
                ptr2->next = n;
                n->next = NULL;
            }  
        }
        ptr2 = ptr2->next;
    }

    head = reverse(head);
    return head;
}

int main()
{

    struct node *head = createLL();
    LLtraversal(head);
    head = add1(head);
    LLtraversal(head);

    return 0;
}