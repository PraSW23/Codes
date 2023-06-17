#include<iostream>
using namespace std;

int paths(int n, int k, int s){

if(((n-1)==k)&&((n-1)==s)){
  return 1;
}

if ((k>=n)||(s>=n))
{
    return 0;
}

   return paths(n,k+1,s) + paths(n,k,s+1);


}



int main(){

int n;
cout<<"Enter the size of maze : ";
cin>>n;
cout<<"The total number of ways are : "<<paths(n,0,0)<<endl;

    return 0;
}