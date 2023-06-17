#include<iostream>
using namespace std;

int main(){
int n,i,j;

cout<<"Enter number : ";
cin>>n;
int arr[n+1];

for ( i = 0; i <= n; i++)
{
    arr[i] = i;
}



for ( i = 2; i <= n; i++)
{
    for ( j = i*i; j <= n; j++)
    {
        if((arr[i]&&arr[j])!=0)
        if (arr[j]%arr[i]==0)
        {
            arr[j] = 0;
        }
        
    }
    
}
cout<<"Prime numbers are : ";
for ( i = 0; i <= n; i++)
{
    if (arr[i]>1)
    {
        cout<<arr[i]<<", ";
    }
    
}
cout<<endl;
return 0;
}