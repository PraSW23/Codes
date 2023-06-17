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

struct node *LLupdation(struct node *head, int old, int new)
{
    struct node *ptr = head;
    if (head == NULL)
    {
        printf("Linked List not intialised or empty\n");
        return head;
    }
    else
    {
        int count = 0;
        while (ptr != NULL)
        {
            if (ptr->data == old)
            {
                printf("%d found at index %d and is replaced by %d\n", old, count, new);
                ptr->data = new;
                return head;
            }
            ptr = ptr->next;
            count++;
        }
    }
    printf("\nOLD value not found in linked list");
    return head;
}

struct node * del_node_of_val(struct node * head, int val){
  
  struct node * prev = head,  * ptr = head;
 int count = 0;
  while (ptr!=NULL)
  {
    if(ptr->data == val ){
        if (ptr == head)
        {
            head = head->next;
            free(ptr);
            return head;
        }
        else
        {
            prev->next = ptr->next;
            free(ptr);
            return head;
        }
    }
    ptr = ptr->next;
    if(count){
    prev = prev->next;
    }
    count = 1;

  }

  printf("Given value not found in linked list \n");
  return head;
}

int main()
{
    int index, val;
    struct node *head = createLL();
    LLtraversal(head);

    int old_data, new_data;
    printf("Enter the old and new value : ");
    scanf("%d %d", &old_data, &new_data);
    head = LLupdation(head, old_data, new_data);
    LLtraversal(head);

    printf("Enter value of node to delete : ");
    scanf("%d", &val);
    head = del_node_of_val(head , val);
    LLtraversal(head);

    return 0;
}