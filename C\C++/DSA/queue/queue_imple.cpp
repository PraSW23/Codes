#include<iostream>
using namespace std;

struct queue
{
    int size;
    int * start;
    int * end;
};


void create_que(struct queue * que){
    que->end = (int *)malloc(sizeof(que->size * sizeof(int)));
    que->start = que->end;   
}


bool isEmpty(struct queue *q){

    if (q->start == q->end)
    {
        return true;
    }
    else return false;

}


bool isFull(struct queue * q){
    if (q->size <= (q->end - q->start))
    {
        return true;
    }
    else return false;
    
}


void enque(struct queue * q, int val){
    if (isEmpty(q))
        {
            q->start =  q->end;
        }
        
     if (!isFull(q))
        {
        
        *(q->end) = val;
        q->end++;   
    }
    else cout<<"Queue is Full (Overflow) !\n";
   
}


void print_que(struct queue * q){
    int * tmp = q->start;
    while (tmp != q->end)
    {
        cout<<(*tmp)<<" ";
        tmp++;   
    }
     cout<<endl;
    
}


void deque(struct queue * q){
    
    if (!isEmpty(q))
    {
       
       int * temp = q->start+1, * prev = q->start;
       
       while (temp - q->start < q->end - q->start)
       {
          * prev = * temp;
            prev++;
            temp++;
       }
        q->end--;
       
    }
    else cout<<"Queue is Empty (underflow)!\n";
    
}


int main(){

    struct queue * q;
    q = (struct queue *)malloc(sizeof(struct queue));

    cout<<"ENTER the size of queue : ";
    cin>>q->size;

    create_que(q);

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
