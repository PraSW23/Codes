#include<iostream>
#include<string>

using namespace std;

void subseq(string s,string ans){
    cout<<ans<<endl;

if(s.length()==0){
    return;
}

char ch = s[0];
string les = s.substr(1);
subseq(les,ans);
subseq(les,ans+ch);
}

int main(){
string s;
cout<<"Enter string : ";
cin>>s;
subseq(s,"");

    return 0;
}