#include<iostream>
using namespace std;

struct node
{
    int data;
    struct node * next;
};


struct queue
{
    int size;
    struct node * start;
    struct node * end;
};


struct queue * create_que(){
   struct queue * q;
    q = (struct queue *)malloc(sizeof(struct queue));
    cout<<"ENTER the size of queue : ";
    cin>>q->size;
    q->end = NULL;
    q->start = NULL;
    return q;
}


bool isEmpty(struct queue *q){

    if (q->start == NULL)
    {
        return true;
    }
    else return false;

}


bool isFull(struct queue * q){
    struct node * temp = q->start;
    int count =0;
    while (temp)
    {
        count++;
        temp = temp->next;
    }

    if(count == q->size)
    {
        return true;
    }
    else return false;
    
}


void enque(struct queue * q, int val){
       
     if (!isFull(q))
    {
        struct node * n = (struct node *)malloc(sizeof(struct node));
        if(q->end != NULL){
        q->end->next = n;
        }
        q->end = n;
        q->end->next = NULL;
        q->end->data = val;
        
        if (isEmpty(q))
        {
            q->start =  q->end;
        }
          
    }
    else cout<<"Queue is Full (Overflow) !\n";
   
}


void print_que(struct queue * q){
    struct node * tmp = q->start;
    while (tmp)
    {
        cout<< tmp->data <<" ";
        tmp = tmp->next;   
    }
     cout<<endl;
    
}


void deque(struct queue * q){
    
    if (!isEmpty(q))
    {
      struct node * temp = q->start;
      q->start = q->start->next;
      
      free(temp);
       
    }
    else cout<<"Queue is Empty (underflow)!\n";

}


int main(){

    struct queue * q;
    

    q = create_que();

    enque(q,50);
    enque(q,9);
    enque(q,67);
    print_que(q);
   
    deque(q);
    print_que(q);
    deque(q);
    print_que(q); 
    deque(q);
    print_que(q);
    deque(q);
    deque(q);
    
    enque(q,98);
    print_que(q);
   
    return 0;
}
