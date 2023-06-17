#include<iostream>
using namespace std;

int main(){
int n,m,i,j,k;

cout<<"Enter no. of rows : ";
cin>>n;
cout<<"\nEnter no. of column : ";
cin>>m;
int a[n][m];
cout<<"Enter Elments : \n";

for ( i = 0; i < n; i++)
{
    for ( j = 0; j < m; j++)
    {
        cin>>a[i][j];
    }
    
}

for ( i = 0; i < n; i++)
{
    for ( j = 0; j < m; j++)
    {
        if ((j==(0))&&(i==(0)))
       {
          j++;
          a[i][j];
       }
       if ((j==(m-1-k))&&(i==0))
       {
          i++;
          a[i][j];  
       }
       if ((j==(m-1-k))&&(i==(n-1-k)))
       {
          j--;
          a[i][j];
       }
       if ((j==(0))&&(i==(n-1-k)))
       {
           i--;
           a[i][j];
       }
       
       

    }
    
    
}




return 0;
}