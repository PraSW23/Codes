#include<iostream>
using namespace std;

int tile(int n){

if (n==0)
{
    return 0;
}
if(n==1){
    return 1;
}

return tile(n-1) + tile(n-2);

}


int main(){
 int n;
 cout<<"Enter value of n for 2*n board : ";
 cin>>n;

 cout<<"No of ways for 2*1 tile on 2*"<<n<<" board are : "<<tile(n)<<endl;

    return 0;
}