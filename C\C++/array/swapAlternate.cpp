#include<iostream>
using namespace std;

int main(){
int n,i,temp,count=0,j;
cout<<"enter number of elements : ";
cin>>n;
int a[n];
cout<<"\nEnter elements : ";

for ( i = 0; i < n; i++)
{
    cin>>a[i];
}

cout<<"\n Alternate numbers : \n";


for ( i = 0; i < n; i++)
{    count++;
    if (count==2)
    {
        temp = a[i-1];
        a[i-1] = a[i];
        a[i] = temp;
        count = 0;
    }
    
}
for ( i = 0; i < n; i++)
{
    cout<<a[i]<<"  ";
}


}