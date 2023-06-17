#include<iostream>
using namespace std;
int main(){
    int n,i=-1,a[50];
    cout<<"Enter number : ";
    cin>>n;
   
  while ((n/2)!=0)
  {    i++;
    a[i]= n%2;
    n = n/2;
    
  }
  if ((n!=0)&&(n/2==0))
  {
     a[++i]= n%2;    
  }
  
  cout<<"\nBinary form is : ";
  while (i!=-1)
  {
    cout<<a[i];
    i--;
  }
  cout<<endl;
}