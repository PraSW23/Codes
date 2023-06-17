#include<iostream>
#include<string>
using namespace std;
int y=1;

void subseq(string s1,string s2,string s3){

if ((s1.length())&&(s2.length()))
{
 cout<<s1[0]<<s2[0]<<endl;
}

if(s2.length()!=0){
  subseq(s1,s2.substr(1),s3);
}else {
        return;
      }

s2 = s3;

if((s1.length()!=0)&&(y)){
 subseq(s1.substr(1),s2,s3);
}else {  y=0;
         return;
       }

}

int main(){
int n1,n2;
string s[] = {"","./","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
cout<<"Enter numbers : ";
cin>>n1>>n2;
subseq(s[n1],s[n2],s[n2]);

    return 0;
}