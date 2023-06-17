#include<iostream>
using namespace std;

int lastoccr(int n, int a[], int k){

    if (a[n]==k)
    {
        return n;
    }
    if(n>0)
return lastoccr(n-1,a,k);
return 0;
}


bool check(int n,int a[]){
        
if (a[n]<a[n-1])
    return 0;

if(n>1)
return check(n-1,a);
return 1;
}

int main(){
    int n,i,s,k;
    cout<<"Enter size of array : ";
    cin>>n;
    int a[n];
    cout<<"Enter elements : ";
    for ( i = 0; i < n; i++)
    {
        cin>>a[i];
    }
    cout<<check(n-1,a)<<endl;
    cout<<"Enter element to find its last occurence in array : ";
    cin>>k;
    s = lastoccr(n-1,a,k);
    if(!s)
    {
        cout<<"Element not found ";
    }else
     cout<<"Last occurence at index "<<s<<endl;
    
    return 0;
}