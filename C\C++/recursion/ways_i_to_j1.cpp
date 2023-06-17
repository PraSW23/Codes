//apna college
#include<iostream>
using namespace std;

int ways(int s,int e){

if (s==e)
{
    return 1;
}

if(s>e){

    return 0;
}

int count = 0;

for (int k = 1; k <=6; k++)
{
    count += ways(s+k,e);
}

    return count;
}


int main(){
   int i,j,y;
   cout<<"Enter initial and final position : ";
   cin>>i>>j;
  // y = ways(i,j);
   cout<<"No of ways to reach from "<<i<<" to "<<j<<" are : "<<ways(i,j)<<endl;
    return 0;
}