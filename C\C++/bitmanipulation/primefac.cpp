#include<iostream>
using namespace std;

int main(){
int i,n;
cin>>n;

for ( i = 2; i <= n; i++)
{
    if ((n%i)==0)
    {   
        cout<<i<<" * ";
        n = n/i;
        i = 1;
    }
    
    //cout<<i<<endl;
}

cout<<"\b";
//cout<<endl;

return 0;
}