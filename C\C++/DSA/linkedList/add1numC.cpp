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
    printf("Enter number of nodes: ");
    scanf("%d", &n);
    printf("Enter data: ");
    struct node *newNode = NULL, *head = NULL, *next = NULL;

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
        printf("\nLinked List is Empty");
        return;
    }

    while (ptr != NULL)
    {
        printf("->%d", ptr->data);
        ptr = ptr->next;
    }
    printf("\n");
}

struct node *reverse(struct node *head)
{
    if (head == NULL || head->next == NULL)
    {
        return head;
    }

    struct node *prev = NULL;
    struct node *current = head;
    struct node *next = NULL;

    while (current != NULL)
    {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }

    head = prev;
    return head;
}

struct node *add1(struct node *head)
{
    head = reverse(head);

    struct node *ptr = head;
    int carry = 1, sum;

    while (ptr != NULL)
    {
        sum = ptr->data + carry;
        ptr->data = sum % 10;
        carry = sum / 10;

        if (carry == 0)
        {
            break;
        }

        if (ptr->next == NULL && carry != 0)
        {
            struct node *newNode = (struct node *)malloc(sizeof(struct node));
            newNode->data = carry;
            newNode->next = NULL;
            ptr->next = newNode;
            break;
        }

        ptr = ptr->next;
    }

    head = reverse(head);
    return head;
}

int main()
{
    struct node *head = createLL();
    printf("Original Linked List: ");
    LLtraversal(head);

    head = add1(head);
    printf("Updated Linked List: ");
    LLtraversal(head);

    return 0;
}
