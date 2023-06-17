#include<stdio.h>
#include<stdlib.h>
//ADT provide abstraction user only use method but not know what is inside the funtion or method

struct array{
    int tot_size;
    int used_size;
    int *ptr;
};

void createArr(struct array * a,int t_size,int use_size){
    
   a->tot_size = t_size;
   a->used_size = use_size; 
   //malloc allocates memory in heap not in stack
   a->ptr = (int *)malloc(t_size*sizeof(int));
    
}

void show_val(struct array *a){

for (int i = 0; i < a->used_size; i++)
{
    printf("\nVal at index %d : %d",i,(a->ptr)[i]);
}
}

void set_val(struct array *a){

for (int i = 0; i < a->used_size; i++)
{
    printf("\nEnter Value of index %d : ",i);
    scanf("%d",&a->ptr[i]);
}

}

void insert_val(struct array *a,int val,int index){

   if (index>=a->used_size)
   {
     a->ptr[a->used_size]= val;
     a->used_size+=1;
   }
   else {
          for (int i = a->used_size-1; i >= index; i--)
          {
               a->ptr[i+1]=a->ptr[i];
          }
          a->ptr[index] = val;
          a->used_size+=1;
   }

}

void delete_val(struct array *a){
    int index;
    printf("\nEnter index to delete from : ");
    scanf("%d",&index);

    if (index>=a->used_size)
    {
        printf("\nEmpty index selected");
    }
    else {
        for (int i = index+1; i <= a->used_size; i++)
        {
            a->ptr[i-1]=a->ptr[i];
        }
        a->used_size-=1;  
    }
}


int main(){
struct array arr;

createArr(&arr,10,4);
set_val(&arr);
show_val(&arr);
insert_val(&arr,29,2);
printf("\n\nvalues after insertion\n");
show_val(&arr);
delete_val(&arr);
 printf("\n\nvalues after deletion\n");
 show_val(&arr); 


}