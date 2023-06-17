#include<iostream>
using namespace std;

int binarySearch(int a[],int y, int n){

int i,j,k;
 
 for ( i = 0; i <= j;)
 {
     k=(i+j)/2;
    
     if (y>a[k])
     {
        i=k+1;
        j=n;
     }
    else {
        i=0;
        j=k-1;
    }
    if (a[k]==y)
    {
        return k;
    }
   
 }

 return -1;
 


}


int main(){
int n, i ,y,x;
cout<<"Enter size of array : ";
cin>>n;
int a[n];
cout<<"\nEnter element : ";

for (i = 0; i < n; i++)
{
    cin>>a[i];
}

cout<<"\nEnter key to find : ";
cin>>y;

 x = binarySearch(a,y,n-1);

if (x==-1)
{
    cout<<"\nElement not found\n";
}
else
 cout<<"\nFound at index "<<x<<endl;


 return 0;
}