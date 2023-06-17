#include<iostream>
#include<string>

using namespace std;

void keypad(string s1,string s2,string ans){

if(s1.length()==0 || s2.length()==0){
   if(s2.length()==0){
   s2 = ans;
   ans = "";
   keypad(s1.substr(1),s2,ans);
   }
    return;
}
cout<<s1[0]<<s2[0]<<endl;
ans = ans+s2[0];
keypad(s1,s2.substr(1),ans);

}


void subseq(string s,string ans){

if(s.length()==0){
    cout<<ans<<endl;
    return;
}

char ch = s[0];
string les = s.substr(1);
subseq(les,ans);
subseq(les,ans+ch);
}

int main(){
    int num1 ,num2;
string s[] = {"","./","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
cout<<"Enter numbers : ";
cin>>num1>>num2;
//subseq(s[num1]+s[num2],"");
keypad(s[num1],s[num2],"");

    return 0;
}