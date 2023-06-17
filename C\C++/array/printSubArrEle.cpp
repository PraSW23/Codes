#include<iostream>
using namespace std;


void threeloop(int n, int a[]){
int i,j,k;

cout<<"All elements of subarray : "<<endl;

for ( i = 0; i < n; i++)
{
    for ( j = i; j < n; j++)
    {
        for ( k = i; k < j; k++)
        {
           cout<<" "<<a[k];

        }
    cout<<endl;
        
    }
    
}
}

int main(){
int n,i;
cout<<"Enter no. of integers : ";
cin>>n;

int a[n];

cout<<"\nEnter the elements : ";

for ( i = 0; i < n; i++)
{
    cin>>a[i];
    
}

    threeloop(n,a);

return 0;
}
