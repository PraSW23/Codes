#include<iostream>
using namespace std;

int main(){
int xori;
int x=8,y=7;
xori = x|y;
cout<<"x|y : "<<xori<<endl;
xori = x&y;
cout<<"x&y : "<<xori<<endl;
xori = x^y;
cout<<"x^y : "<<xori<<endl;

//swap using xor
x = x^y;
y = x^y;
x = x^y;

cout<<"Values after swap are x = "<<x<<" and y = "<<y<<endl;
cout<<"x xor x : "<<(x^x)<<endl;
return 0;
}