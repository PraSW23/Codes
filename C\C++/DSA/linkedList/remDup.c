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

struct node *deleteLL(struct node *head, struct node *ptr)
{
    struct node *ptr2 = ptr->next;
    ptr->next = ptr->next->next;
    free(ptr2);
    return ptr->next;
}

struct node *remdup(struct node *head)
{
    struct node *ptr1 = head, *ptr2 = head->next;

    while (ptr2 != NULL)
    {
        if (ptr1->data == ptr2->data)
        {
            ptr1->next = deleteLL(head, ptr1);
            ptr2 = ptr1->next;
        }
        else
        {
            ptr1 = ptr1->next;
            ptr2 = ptr2->next;
        }
    }
    return head;
}

int main()
{

    struct node *head = createLL();
    LLtraversal(head);
    head = remdup(head);
    LLtraversal(head);

    return 0;
}