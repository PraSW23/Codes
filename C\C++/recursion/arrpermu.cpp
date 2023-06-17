#include <iostream>
using namespace std;

void printarr(int arr[],int n){

for (int i = 0; i <= n; i++)
{
    cout<<arr[i];
}
cout<<endl;

}

void permu(int arr[], int start , int end){

if(start == end){
    printarr(arr,end);
}

  for (int i = start; i <= end; i++)
  {
    swap(arr[i],arr[start]);
    permu(arr,start+1,end);
    swap(arr[i],arr[start]);
  }


}

int main(){

int n;
cout<<"Enter the number of elements : ";
cin>>n;

int arr[n],ans[n];
cout<<"\nEnter elements ";

for (int i = 0; i < n; i++)
{
    cin>>arr[i];
}

permu(arr,0,n-1);

return 0;
}