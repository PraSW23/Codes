#include<iostream>
using namespace std;

bool getbit(int n, int i){
    return ((1<<i)&(n));
}

int clearbit(int n, int i){
    return ((~(1<<i))&(n));
}


int setbit(int n, int i){
    //clearbit(n,i);
  return ((1<<i)|(n));
}


 int main(){
 int n=10,i=0;
 
 cout<<"bit at "<<i<<" position is "<<getbit(n,i)<<endl;
 cout<<"After setting bit at "<<i<<" position, number is "<<(n=setbit(n,i))<<endl;
 cout<<"After clearing bit at "<<i<<" position, number is "<<clearbit(n,i)<<endl;
return 0;
 }