    #include<stdio.h>
    #include<stdlib.h>

    struct node {
        int data;
        struct node * prev, *next;
    };

    struct node * createLL(int n){
    int data;
    struct node * head , *ptr;
    printf("\nEnter data : ");

    for(int i=1;i<=n;i++){
        scanf("%d", &data);
        struct node * nod = (struct node *)malloc(sizeof(struct node));
        nod->data = data;
        nod->prev = NULL;
        nod->next = NULL;

        if(i==1){
            head = nod;
            ptr = nod;
        }else{
            ptr->next = nod;
            nod->prev  = ptr;
            ptr = ptr->next;
        }
        
    }
        return head;
    }
    void LLtraverse(struct node* head) {
    struct node* ptr = head;

    printf("Traversal forward: ");
    while (ptr->next != NULL) {
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }
    printf("%d ", ptr->data);
    
    printf("\nTraversal backward: ");
    while (ptr != NULL) {
        printf("%d ", ptr->data);
        ptr = ptr->prev;
    }
    printf("\n");
    }

    void LLtraversal(struct node * ptr){

    while(ptr!=NULL){
        printf("->%d",ptr->data);
        ptr=ptr->next;
        if(ptr->next == NULL){
            do{
                printf("->%d",ptr->data);
                ptr=ptr->prev;
            }while(ptr!=NULL);
        }
    }
    printf("\n");

    }

    struct node * insertionLL(struct node * head , int index , int data){
        int count=1;
        struct node * ptr = head;
        struct node * node = (struct node *)malloc(sizeof(struct node));
        node->data = data;
        node->prev = NULL;
        node->next = NULL;

        do{
            if(index==0){
                node->next = ptr;
                ptr->prev = node;
                return node;
            }else{
                if(count==index){
                    node->prev = ptr;
                    if(ptr->next != NULL){
                    node->next = ptr->next;
                    ptr->next->prev = node;
                    }
                    ptr->next  = node;
                    return head;
                }
                ptr=ptr->next;
                count++;
            }
        }while(ptr!=NULL);
        printf("\nERROR ! Invalid index \n\n");
        return head;

    }

    int main(){
    int n, data,index;
    struct node * head;
    printf("Enter the number of nodes : ");
    scanf("%d", &n);
    
    head = createLL(n);
    LLtraversal(head);
    LLtraverse(head);

    printf("Enter data and index : ");
    scanf("%d %d",&data, &index);
    head = insertionLL(head, index , data);
    LLtraversal(head);
    LLtraverse(head);

        return 0;
    }