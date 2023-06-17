#include<iostream>
using namespace std;

int main(){
int n1,m1,n2,m2,i,j,k,sum=0;
cout<<"\nMatrix 1 \n";
cout<<"Enter no. of rows : ";
cin>>n1;
cout<<"\nEnter no. of column : ";
cin>>m1;
int a1[n1][m1];
cout<<"Enter Elments : \n";

for ( i = 0; i < n1; i++)
{
    for ( j = 0; j < m1; j++)
    {
        cin>>a1[i][j];
    }
    
}
cout<<"\nMatrix 2 \n";
cout<<"Enter no. of rows : ";
cin>>n2;
cout<<"\nEnter no. of column : ";
cin>>m2;

int a2[n2][m2];

if (m1==n2)
{  
    cout<<"\nEnter Elments : \n";

for ( i = 0; i < n2; i++)
{
    for ( j = 0; j < m2; j++)
    {
        cin>>a2[i][j];
    }
}
}
else {
       cout<<"\nMultiplication not possible \n";
       return 0;
}

int mul[n1][m2];

for ( i = 0; i < n1; i++)
{      
        

    for ( k = 0; k < m2; k++)
    {   sum = 0;
        for ( j = 0; j < m1; j++)
        {
            sum = sum + a1[i][j]*a2[j][k];
        }
        
        mul[i][k] = sum;

    }
    
}
cout<<"\nMultiplied matrix : \n";
for ( i = 0; i < n1; i++)
{
    for ( k = 0; k < m2; k++)
    {
        cout<<mul[i][k]<<"  ";
    }
    cout<<endl;
}




return 0;
}