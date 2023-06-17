#include<iostream>
using namespace std;
int main(){
int  a = 10,bv = 20;
int *ap,*b;

b = &bv;
ap = &a;
//ap = b;
cout<<"\na = "<<a;
cout<<"\n&a = "<<&a;
cout<<"\n*(&a) = "<<*(&a);
cout<<"\nb = "<<b;
cout<<"\n*b = "<<*b;
cout<<"\n&b = "<<&b;
cout<<"\nap = "<<ap;
cout<<"\n*ap = "<<*ap;
cout<<"\n&ap = "<<&ap<<endl;
return 0;
}