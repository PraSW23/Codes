#include<iostream>
using namespace std;

int fib(int n){
   if (n==1)
   {
    return 0;
   }else if (n==2)
   {
    return 1;
   }else return fib(n-1) + fib(n-2);
}

int main(){
int n;
cout<<"Enter number : ";
cin>>n;
cout<<"Factorial is : "<<fib(n)<<endl;

return 0;
}