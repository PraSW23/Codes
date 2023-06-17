//best method
#include<iostream>
#include<string>
using namespace std;

string last(string s){
 
 if(s.length()==0)
 return "";
  
 char ch = s[0];
 string ans = last(s.substr(1));

 if(ch=='x')
 return ans + ch;
 else return ch + ans;

}

int main(){
string s,l;
cout<<"Enter string : ";
cin>>s;
cout<<"x at last : "<<last(s)<<endl;
    return 0;
}