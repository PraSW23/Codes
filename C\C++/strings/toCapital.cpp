#include<iostream>
#include<algorithm>
#include<string>
using namespace std;

int main(){
      int i,y;
string s1;
cout<<"Enter string to convert into CAPITAL : ";
cin>>s1;

for ( i = 0; i < s1.length(); i++)
{    y = s1[i];
     y-=32;
     
    if((y>64)&&(y<92)){
       s1[i]=y;
    }
}
cout<<s1<<endl;

transform(s1.begin(),s1.end(),s1.begin(),::tolower);
cout<<s1<<endl;



return 0;
}