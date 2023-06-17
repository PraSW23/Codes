#include<iostream>
#include<math.h>
using namespace std;

bool getbit(int n, int i){
    return ((1<<i)&(n));
}


int main(){
    int n, i,j;
    cout<<"Enter number of elements : ";
    cin>>n;
char arr[n];
cout<<"Enter elements : ";
for ( i = 0; i < n; i++)
{
    cin>>arr[i];
}

for ( i = 0; i < pow(2,n); i++)
{  cout<<"{ ";
    for ( j = 0; j < n; j++)
    {
       if(getbit(i,j)){
        cout<<arr[j]<<" ,";
       } 
    }
    cout<<"\b}";
    cout<<endl;
    
}

return 0;
}