#include<iostream>
using namespace std;

void Sort(int a[],int n){
   int i,j=0,k,min; 

  while (j<n-1)
  {
    for ( i = j+1; i < n; i++)
    {
          if (a[j]>a[i])
     {
        k = a[j];
        a[j] = a[i];
        a[i] = k;
     }
    }
      
    j++;

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

   Sort(a,n);



 return 0;




}