#include<iostream>
using namespace std;
int sumofn(int n)
{ int sum=0;
    while (n!=0)
    {
        sum = sum + n;
        
        n--;
    }
    return sum;
}
int main(){
    int n;
    cout<<"Enter the number : ";
    cin>>n;
    cout<<"\nSum is "<<sumofn(n)<<endl;
    return 0;


}