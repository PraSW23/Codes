#include<iostream>
using namespace std;

int main(){
 int n,i,j,k,t,temp;

 cout<<"Enter the number of lines : ";
 cin>>n;

 for(i=1;i<=n;i++){
    int arr[i+1],ar[i];

   for(j=n;j>=i;j--){
    cout<<" ";
   }
   for(k=1;k<=i;k++){
    ar[0]=1;
    arr[0]=1;
    ar[i-1]=1;
    arr[i]=1;
    
    if(k<i){
        arr[k]=ar[k-1]+ar[k];
    }
    if(i>3 && k<i-1){
        ar[k]=arr[k];
    }

   }
   for(t=0;t<=i;t++){
     cout<<arr[t]<<" ";
   }

   cout<<"\n";
 } 


    return 0;
}