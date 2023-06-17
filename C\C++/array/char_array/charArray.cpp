#include<iostream>
using namespace std;

int main(){
int i=0;
char arr[100]= "hello my name";

while (arr[i]!='\0')
{
    cout<<endl<<arr[i]<<endl;
    i++;
}

cout<<endl<<arr<<endl;


 return 0;
}