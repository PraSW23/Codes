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

struct node *cancel_neg(struct node *head)
{
    struct node *ptr = head, *temp = head;

    while (ptr != NULL)
    { // int sum = 0;
        if (ptr->data < 0)
        {
            while (temp != NULL)
            {
                if (ptr->data == (-1) * (temp->data))
                {
                    ptr->data = 0;
                    temp->data = 0;
                    temp = head;
                    break;
                }
                temp = temp->next;
            }
        }
        ptr = ptr->next;
    }
    return head;
}

int main()
{
    int index, val, mid;
    struct node *head = createLL();
    LLtraversal(head);
    cancel_neg(head);
    LLtraversal(head);

    return 0;
}