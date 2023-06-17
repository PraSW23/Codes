//unique numbers are the numbers that are occuring 1 time while other are occuring thrice
#include<iostream>
#include<math.h>
using namespace std;

bool getbit(int n, int i){
    return ((1<<i)&n);
}

int main(){
int i,n,num=0,a[32],count,j;
cout<<"Enter no of elements : ";
cin>>n;
int arr[n];
cout<<"Enter elements : ";

for ( i = 0; i < n; i++)
{    
    cin>>arr[i];    
}

for ( i = 0; i < 32; i++)
{  count = 0;
   for (j = 0; j < n; j++)
   {

    if(getbit(arr[j],i)==1){
        count++;
    }
    
   }
   a[i]=count;
   num = num + (a[i]%3)*(pow(2,i));
}

cout<<"Unique number is : "<<num<<endl;

return 0;
}