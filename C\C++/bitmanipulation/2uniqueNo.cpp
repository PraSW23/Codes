//unique numbers are the numbers that are occuring 1 time while other are occuring twice
#include<iostream>
using namespace std;

bool getbit(int n, int i){
    return ((1<<i)&(n));
}

int main(){
int i,n,xorsum,tempxor,pos=0;
cout<<"Enter no of elements : ";
cin>>n;
int arr[n];
cout<<"Enter elements : ";

for ( i = 0; i < n; i++)
{    
    cin>>arr[i];
    if (i>0)
    {
        xorsum = xorsum^arr[i];
    }else xorsum = arr[i];
    
}
tempxor = xorsum;

while (getbit(xorsum,pos)==1)
{
    pos++;
}
for ( i = 0; i < n; i++)
{
     if (getbit(arr[i],pos-1)==1)
     {
        xorsum=xorsum^arr[i];
     }
     
}
cout<<"First unique number is : "<<xorsum<<"\nSecond unique number is : "<<(tempxor^xorsum)<<endl;

return 0;
}