#include<iostream>
using namespace std;

int fac(int n){
   if (n==0)
   {
    return 1;
   }else if (n==1)
   {
    return 1;
   }else return n*fac(n-1);
}

int main(){
int n;
cout<<"Enter number : ";
cin>>n;
cout<<"Factorial is : "<<fac(n)<<endl;

return 0;
}