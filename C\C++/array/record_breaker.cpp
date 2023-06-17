#include<iostream>
using namespace std;

int main(){
int i,n,max=0,count=0;
cout<<"Enter no. of integers : ";
cin>>n;
int a[n];
cout<<"\nEnter the elements : ";

for ( i = 0; i < n; i++)
{
    cin>>a[i];
}

if (n==1)
{
    cout<<"No. of record breaking days are : 1"<<endl;
}


for ( i = 0; i < n; i++)
{
  if (max<a[i])
  {
     max = a[i];
     if (a[i]>a[i+1])
     {
        count++;
     }
     
  }
}
     cout<<"\nNo. of record breaking days : "<<count<<endl;


}