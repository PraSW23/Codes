#include<iostream>
using namespace std;

void permu(int arr[], int n, int i){

if(i==n){
    for(int k=0;k<=n;k++)
    cout<<arr[k];
    cout<<endl;
    return;
}
for (int j = i; j <= n; j++)
{
    swap(arr[i],arr[j]);
    permu(arr,n,i+1);
    swap(arr[i],arr[j]);
}   
}


int main(){
    int n;
    cout<<"Enter the number of elements : ";
    cin>>n;

 int arr[n],ans[n];
 cout<<"Enter elments : ";
 
 for (int i = 0; i < n; i++)
 {
    cin>>arr[i];
 }
 cout<<"Permutation are : "<<endl;

 permu(arr,n-1,0);
 
    return 0;
}