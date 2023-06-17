#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
unsigned long long int getModulo(unsigned long long int n,
                       unsigned long long int d)
{
  return ( n & (d - 1) );
} 

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */  
    int a[4];
   long long int i,max=1,count=1,k;
    
    for(i=0;i<4;i++){
        cin>>a[i];
    }
    
    if(a[0]<0)
     k = (-1)*a[0];
     else k=a[0];
    
    long long int arr[k];
     
        arr[0]= getModulo(a[1],pow(2,31));
        cout<<arr[0]<<" ";
        for(i=1;i<a[0]-1;i++){
            arr[i] = (arr[i-1]*a[2])+(getModulo(a[3],(pow(2,31))));
            cout<<arr[i]<<" ";
        }
        
    for(i=1;i<=(k-1);i++){
        if(arr[i-1]!=arr[i]){
         count++; 
         } else if(max<count){
             max =count;
             count =1;
        }
          if(i==a[0]-1)
         if(max<count){
             max =count;}
    }
    cout<<max;
     
    return 0;
}