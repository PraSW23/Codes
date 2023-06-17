#include<iostream>
using namespace std;

int main(){
int i,max=0,n;
cout<<"Enter no of integers : ";
cin>>n;
int a[n];
cout<<"\nEnter the elements : ";

for ( i = 0; i < n; i++)
{
    cin>>a[i];
    if (max<a[i])
    {
        max = a[i];
    }
    
}

bool idx[max+1];
for ( i = 0; i < max+1; i++)
{
    idx[i] = 0;
}

for ( i = 0; i < n; i++)
{
    if ((idx[a[i]]==0)&&(a[i]>-1))
    {
         idx[a[i]] = 1;
    }
}

for ( i = 0; i < max+1; i++)
{
    if (idx[i]==0)
    {
        cout<<"Missing no. is "<<i<<endl;
        break;
    }
    
}


}