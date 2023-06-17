/*elment must repeat and index must be small
input = {0,1,5,3,3,2,5,6}
output = 2 
because in above array input 5 and 3 is repeating and 5 index is smaller (=2) and 3 index is larger(=3)
so ans is 2 */

#include<iostream>
using namespace std;

int main(){
int i,n,max=0;
cout<<"Enter no. of integers : ";
cin>>n;
int a[n], min=n+1;

cout<<"\nEnter the elements : ";

for ( i = 0; i < n; i++)
{
    cin>>a[i];
    if(max<a[i]){
        max = a[i];
    }
}
  int idx[max+1];

for ( i = 0; i < max+1; i++)
{
    idx[i] = -1;
}

for ( i = 0; i < n; i++)
{   
    if (idx[a[i]]==-1)
    {
         idx[a[i]] = i;
    }
    else if (idx[a[i]]>0)
    {
        min = idx[a[i]];
        
    }
}
if(min==(n+1))
cout<<"No numbers are repeating \n";
else cout<<"Ans(index) is "<<min<<endl;

return 0;
}