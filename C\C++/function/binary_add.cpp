#include<iostream>

using namespace std;

int main(){
   uint n,m,y,z;

   
   uint x[6]={0,0,0,0,0,0},i,j;
   cout<<"Enter number 1 = ";
   cin>>n;
   cout<<"\nEnter number 2 = ";
   cin>>m;
   

 for ( i = 5; i >1; i--)
 {
    
   y=n%10;
   n=n/10;
   z=m%10;
   m=m/10;
   x[i]=x[i]+y+z;
   if (x[i]==2)
   {
      x[i]=0;
      x[i-1]=1;

   }else if (x[i]==3)
   {
     x[i]=1;
     x[i-1]=1;
   }
   
 }  
 cout<<"\nSUM is "; 
for ( i = 0; i <6; i++)
{
    cout<<x[i];
}
  
cout<<"\n";
 
}