#include<iostream>
#include<math.h>
using namespace std;

int maxpow(int n){
int count =0;
while (n/2 != 0)
{
    count++;
    n = n/2;
}
return count;
}

void cal(int n){
   int y=n;
   int left;
  
       n = maxpow(n);
       left = y - pow(2,n);// cout<<")";

   if(n==0)
    cout<<"2(0)";
 
   if(n==1)
    cout<<"2";
    
   if(n>1)
     { cout<<"2(";
        cal(n); 
       cout<<"\b)";
         } cout<<"+";
   if(left!=0)
     cal(left); 
  
}

int main(){
int n;
cout<<"Enter number : ";
cin>>n;
cal(n);
cout<<"\b";

return 0;

}