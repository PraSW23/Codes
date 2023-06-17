#include<iostream>
using namespace std;
void binary(int n){
    int i=-1,a[50];
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

int main(){
    int n;
    cout<<"Enter number : ";
    cin>>n;
    binary(n);
    
}