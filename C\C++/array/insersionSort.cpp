#include<iostream>
using namespace std;
void insersionSort(int a[], int n){
  int i,j,temp;
for ( i = 0,j=1; i < n,j<n; i++,j++)
{
    
      while (a[j]<a[i])
      {
        j--;
        i--;
      }
        temp = a[j+1];
        while(i<j){
            a[j+1]=a[--j];
        }
         a[j+1]=temp;
    


}

 



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

   insersionSort(a,n);



 return 0;



}