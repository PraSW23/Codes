/*Given an unsorted array of size N of non-negative integers , find a continous subarray which adds
 to  a given number s.
*/
#include<iostream>
using namespace std;
int main(){
int i,s,sum,j,n;

cout<<"Enter no of integers : ";
cin>>n;
int a[n];
cout<<"\nEnter the elements : ";
for ( i = 0; i < n; i++)
{
    cin>>a[i];
}
cout<<"Enter s : ";
cin>>s;


for ( i = 0; i < n-1; i++)
{   sum = a[i];
    for ( j = i+1; j < n; j++)
    {
        if (sum<s)
        {
            sum = sum + a[j];
            
           if (sum == s)
          {
             cout<<"The sum from index "<<i<<" to index "<<j<<" is "<<s<<endl;
          }
        }
        else break;
        
    }
    
}


return 0;
}