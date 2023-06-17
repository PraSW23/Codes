#include<iostream>
using namespace std;


int no_of_ones(int n){
    int count=0;
  while(n){
    n = n&(n-1);
   count++;
  }
return count;
}

int main(){
 int n;
 cout<<"Enter number : ";
 cin>>n;

 if ((n-1)&(n))
 {
     cout<<"not power of 2 "<<endl;
 }else cout<<"power of 2 "<<endl;
   
   cout<<"the number of ones are : "<<no_of_ones(n)<<endl;

    return 0;
}