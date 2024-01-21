
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

int is_full(struct queue * q){
    int count=0,count2=0;
    struct node * temp = q->end;
    if (temp == NULL && q->size > 0)
    {
       
        return 1;
    }
    else do {
        count++;
        temp=temp->next;
    }while (temp!=q->end);
    //cout<<"count = "<<count<<endl;

    if(q->start!=NULL)
        temp = q->start;
    
    while (temp!=q->end->next)
    {
        count2++;
        temp = temp->next;
    }
    

    if (count < q->size )
    {
        // cout<<"count = "<<count<<"\n";
        return 1;
    }
    else if (count == q->size && count2==count)
    {
        return 2;
    };

    return 0;
    
}

void enque(struct queue * q, int val){
       
     if (is_full(q)!=2 )
    { 
        if (isEmpty(q) && q->end != NULL)
        {
            q->start =  q->end;
           
        }
        if (is_full(q)==1)
        {   
            struct node * n = (struct node *)malloc(sizeof(struct node));
            n->data = val;
            if(q->end != NULL){
                q->end->next = n;
            }
            q->end = n;
            if (isEmpty(q))
            {
                q->start = q->end;
            }
            q->end->next = q->start;
            
        }else{
            
            q->end->data = val;
            if (q->start==NULL)
            {
                q->start = q->end;
            }
            
            q->end = q->end->next;
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
    else do {
        cout<<tmp->data<<" ";
        tmp = tmp->next;
    }while (tmp != q->end->next);
    

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
