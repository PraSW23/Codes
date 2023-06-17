#include<iostream>
using namespace std;

int main(){
int i,length=2,max=2,n;

cout<<"Enter no of integers : ";
cin>>n;
int a[n];
cout<<"\nEnter the elements : ";

for ( i = 0; i < n; i++)
{
    cin>>a[i];
}


for ( i = 1; i < n-1; i++)
{
    if((a[i]-a[i-1])==(a[i+1]-a[i])){
      length = length + 1;
      if (length>max)
      {
        max = length;
      }
     
    } 
    else{
        length = 2;
      }
}

cout<<"\nMax lenght of arithmetic subarray : "<<max<<endl;
return 0;
}