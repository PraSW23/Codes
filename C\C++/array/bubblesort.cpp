#include<iostream>
using namespace std;

void bubbleSort(int a[], int n){
    int i,j,temp;
 
 for ( i = 1; i < n; i++)
 {
    for ( j = 0; j < n-i; j++)
    {
        if(a[j]>a[j+1]){
            temp = a[j+1];
            a[j+1] = a[j];
            a[j] = temp;
        }
    }

 }
 
cout<<"\nSorted array : ";

  for (i = 0; i < n; i++)
{
    cout<<a[i]<<" ";

}
   cout<<"\n";
  

}


int main(){

int n, i ;
cout<<"Enter size of array : ";
cin>>n;
int a[n];
cout<<"\nEnter element : ";

for (i = 0; i < n; i++)
{
    cin>>a[i];
}

   bubbleSort(a,n);



 return 0;



}