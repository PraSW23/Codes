#include<iostream>
using namespace std;

void tow(int n,char A, char C,char B){

if(n==0){
return;
} 
   tow(n-1,A,B,C);
    cout<<"Move Disk "<<n<<" from "<<A<<" to "<<C<<endl;
   tow(n-1,B,C,A);
}

int main(){
int n;
cout<<"Enter number of disks : ";
cin>>n;
tow(n,'A','C','B');

return 0;
}