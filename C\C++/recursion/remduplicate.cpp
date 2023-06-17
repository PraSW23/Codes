#include<iostream>
#include<string>
using namespace std;

//if duplicate characters are continues
string rem(string s){
if (s.length()==0){
  return "";
}
char ch = s[0];
string ans = rem(s.substr(1));

if(ch==ans[0]){
  return ans;
}

return (ch+ans);

}



void remdup(string s){
    if(s.length()==0){
        cout<<endl;
        return ;
    }
    cout<<s[0];
   
   for (int i = 1; i < s.length(); i++)
   {
      if(s[i]==s[0]){
        s.erase(i,1);
        i-=1;
      }
   }
   remdup(s.substr(1));

}


int main(){
string s;
cout<<"Enter string : ";
getline(cin,s);
//cin>>s;
cout<<rem(s);

    return 0;
}