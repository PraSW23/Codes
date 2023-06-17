#include<iostream>
using namespace std;

int ways(int i,int j){

if (i==j)
{
    return 1;
}

int c=0;
 if(i+1<=j)
c =c + ways(1+i,j);
 if(i+2<=j)
c =c + ways(2+i,j);
 if(i+3<=j)
c =c + ways(3+i,j);
 if(i+4<=j)
c =c + ways(4+i,j);
 if(i+5<=j)
c =c + ways(5+i,j);
 if(i+6<=j)
c =c + ways(6+i,j);
    
return c;
}


int main(){
   int i,j,y;
   cout<<"Enter initial and final position : ";
   cin>>i>>j;
   y = ways(i,j);
  cout<<"No of ways to reach from "<<i<<" to "<<j<<" are : "<<y<<endl;
    return 0;
}