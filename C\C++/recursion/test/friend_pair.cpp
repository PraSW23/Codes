#include<iostream>
using namespace std;

int pairs(int n){

    if (n==0)
    {
        return 1;
    }

    if (n<0)
    {
        return 0;
    }
    
    return pairs(n-1) + (n-1)*pairs(n-2);

}

int main(){
    int n;
    cout<<"Enter the number of friends : ";
    cin>>n;
    cout<<"ans = "<<pairs(n)<<endl;
    return 0;
}