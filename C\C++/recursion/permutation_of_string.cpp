//not complete
#include<iostream>
#include<string>
using namespace std;

void per(string s, string ans){
string in ="";
if(s.length()==0){
    return;
}
   // cout<<ans+s<<endl;
   
  char ch = s[0];
  per(s.substr(1),ans+ch);

 in  =in+s[0];

   
   s.insert(s.length(),in);
   s.erase(0,1);
    cout<<ans+s<<endl;
  
 
}


int main(){
 string s;
 cout<<"Enter String : ";
 cin>>s;
 per(s,"");


    return 0;
}