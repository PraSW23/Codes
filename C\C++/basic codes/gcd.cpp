#include<iostream>
using namespace std;

int gcd(int a, int b){
 
 while (b!=0)
 { int rem = a%b;
    a = b;
    b = rem;
 }
 
return a;
}

int main(){
int a,b;
cout<<"Enter two numbers : ";
cin>>a>>b;

cout<<"HCF(GCD) is : "<<gcd(a,b)<<endl;

return 0;
}