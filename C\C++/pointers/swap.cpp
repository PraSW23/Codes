#include<iostream>
using namespace std;

void swap(int *ap, int *bp){
int temp;
temp = *ap;
 *ap = *bp;
*bp = temp;
}

int main(){
int a=10,b=20;
int *ap , *bp = &b;
ap = &a;

swap(ap,bp);
cout<<"a = "<<a<<" and b = "<<b<<endl;
return 0;
}