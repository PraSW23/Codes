#include<iostream>
using namespace std;

int friends_pair(int n){

if (n==0||n==1||n==2)
{
    return n;
}

  return friends_pair(n-1) + (n-1)*friends_pair(n-2);

    
}


int main(){
int n;
cout<<"Enter number of friends : ";
cin>>n;
cout<<"Total number of ways are : "<<friends_pair(n)<<endl;

    return 0;
}