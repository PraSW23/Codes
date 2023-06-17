#include<iostream>
#include<string>

using namespace std;

void subseq(string s,string ans){

if(s.length()==0){
    cout<<ans<<endl;
    return;
}

char ch = s[0];
int x = ch;

string les = s.substr(1);
subseq(les,ans);
subseq(les,ans+ch);
subseq(les,ans+to_string(x));
}

int main(){
string s;
cout<<"Enter string : ";
cin>>s;
subseq(s,"");

    return 0;
}