    #include<stdio.h>
    #include<stdlib.h>
    #include<limits.h>

    struct stack {
        int size;
        int * arr;
        int top;
    };

    struct stack * CreateSTK(int size){
    struct stack * sp = (struct stack *)malloc(sizeof(struct stack));
    sp->size = size;
    sp->top = -1;
    sp->arr = (int *)malloc(sizeof(int) * sp->size);
    return sp;
    }

    void traverseSTK(struct stack * sp){

    if(sp->top == -1){
        printf("\nStack is empty ");
        return;
    }
    int in = sp->top;
    while(in != -1){
        printf("%d\n",sp->arr[in--]);
    }
    }

    void push(int val, struct stack * sp){
        if(sp->top == sp->size-1){
            printf("Stack Overflow can'nt push %d\n",val);
        }
        else sp->arr[++sp->top] = val;
    }

    int pop(struct stack * sp){
        if(sp->top == -1){
            printf("\nUnable to pop Stack is Empty\n");
            return INT_MIN;
        }
        else{
            int popped = sp->arr[sp->top];
            sp->arr[sp->top--] = INT_MIN;
            printf("\n%d is popped from from top of the stack \n",popped);
            return popped;
        }
    }
    int peek(int index,struct stack * sp){
        if(index<0){
            printf("\nInvalid index\n");
            return INT_MIN;
        }
        else if(index > (sp->size-1)){
            printf("\nIndex out of range\n");
            return INT_MIN;
        }else{
            int val = sp->arr[index];
            printf("\nvalue at index is %d \n", val);
            return val;
        }
    }

    int main(){
        int size;
    printf("Enter size of stack : ");
    scanf("%d",&size);
    struct stack * sp = CreateSTK(size);
    push(80,sp);
    push(32,sp);
    push(94,sp);
    push(25,sp);
    push(10,sp);

    traverseSTK(sp);

    int pop_val = pop(sp);
    printf("Popped value is %d \n",pop_val);  
    
    printf("Value at index 3 is %d\n",peek(-1,sp));

        return 0;
    }
