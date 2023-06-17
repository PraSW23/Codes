#include<iostream>
using namespace std;

int main(){
int n,m,i,j,k,s,temp;
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
cout<<"Enter number to find : ";
cin>>s;

//search

/*if (n>m)
{
    temp = n;
    n = m;
    m = temp;
}*/

for ( int l = 0; l < n; l++)
{
      j = m-1;
    for ( i = 0; i < m; i++)
  {  
     k = (i+j)/2;
     
     if (a[l][k]>s)
    {
         j = k;
     }else if (a[l][k]<s)
     {
        i = k;
     }else if (a[l][k]==s)
     {
        cout<<"\nElement is found in "<<l+1<<" row and "<<i+1<<" column\n";
     }          
     
  
}

}


return 0;
}