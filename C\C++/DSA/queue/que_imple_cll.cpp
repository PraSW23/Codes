// implementation of queue using circular ll but node as increases to allowed size as required
// and at last makes it cicular
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
    
    if ( q->end == NULL)
    {
        return false;
    }
    

    if (q->start == q->end->next)
    {
        
        return true;
    }
    else return false;
    
    
}

int end_ll(struct queue * q){
    int count=0;
    struct node * temp = q->start;

    while (temp!=NULL)
    {
        if (temp->next == q->start)
        {
            return count;
        }
        
        count++;
        temp=temp->next;
        
    }

    if (count==q->size)
    {
        return 2;
    }
    else return 1;
    
}

void enque(struct queue * q, int val){
       
     if (!isFull(q))
    { 
        if (end_ll(q)==1)
        {
            struct node * n = (struct node *)malloc(sizeof(struct node));
            n->next = NULL;
            n->data = val;
            if(q->end != NULL){
                q->end->next = n;
            }
            q->end = n;
        }else{
            q->end->data = val;
            q->end = q->end->next;
        }
        if (isEmpty(q))
        {
            q->start =  q->end;
        }

        if(end_ll(q)==2){
        q->end->next = q->start;
        } 
          
    }
    else cout<<"Queue is Full (Overflow) !\n";
   
}


void print_que(struct queue * q){
    struct node * tmp = q->start;
    if (tmp==NULL)
    {
        return;
    }

    do{
        cout<< tmp->data <<" ";
        tmp = tmp->next;   
    }while (tmp!=q->end->next && tmp!=NULL);

     cout<<endl;
    
}


void deque(struct queue * q){
    
    if (!isEmpty(q))
    {
      if (q->start == q->end)
      {
         q->start = NULL;
      }
      else q->start = q->start->next;
      
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
    enque(q,99);
    enque(q,100);
    print_que(q);
   
    return 0;
}
