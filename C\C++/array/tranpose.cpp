#include<iostream>
using namespace std;

int main(){
int n,m,i,j,k;

cout<<"Enter no. of rows : ";
cin>>n;
//cout<<"\nEnter no. of column : ";
//cin>>m;
int a[n][n],temp;
cout<<"Enter Elments : \n";

    for ( i = 0; i < n; i++)
    {
        for ( j = 0; j < n; j++)
        {
            cin>>a[i][j];
        }
        
    }
cout<<"\nTranspose of matrix is : \n";

for (i = 0; i < n; i++)
{
    for ( j = 0; j < i; j++)
    {
       
           temp = a[i][j];
            a[i][j] = a[j][i];
            a[j][i] = temp;
          
    }
        
}
for ( i = 0; i < n; i++)
{
    for ( j = 0; j < n; j++)
    {
        cout<<a[i][j]<<" ";
    }
    cout<<endl;
}


return 0;
}