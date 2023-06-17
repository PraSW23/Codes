#include<iostream>
#include<cstring>
using namespace std;

int main(){
int i=0,j=-1;
char arr[100];
cout<<"Enter string : ";
cin>>arr;

/*
while (arr[i]!='\0')
{
    j++;
    i++;
}
*/
j = strlen(arr) - 1 ;
//cout<<"j = "<<j<<endl;
i = 0;
while (i<=j)
{
    if (arr[i] != arr[j])
    {
        cout<<"Not palindrome\n";
        return 0;
    }
  i++;
  j--;
    
}
cout<<"Palindrome\n";


}