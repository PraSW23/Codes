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

struct node *middleLL(struct node *head)
{
    struct node *ptr1 = head, *ptr2 = head;
    int count = 1;

    while (ptr2 != NULL)
    {
        if (ptr2->next == NULL)
        {
            break;
        }
        ptr2 = ptr2->next->next;
        if (count == 1)
        {
            count = 0;
            continue;
        }
        ptr1 = ptr1->next;
    }
    return ptr1;
}

struct node *deleteLL(struct node *head, struct node *ptr)
{
    struct node *ptr2 = ptr->next;
    ptr->next = ptr->next->next;
    free(ptr2);
    return head;
}

int main()
{
    int index, val;
    struct node *head = createLL(), *mid;
    LLtraversal(head);

    mid = middleLL(head);

    head = deleteLL(head, mid);
    LLtraversal(head);

    return 0;
}