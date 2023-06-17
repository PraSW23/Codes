#include<iostream>
#include<string>
using namespace std;

string last(string s, int n, int i, int l){

 if((i==l)||(i>l))
    return s;


 if(s[i]=='x'){
     if (s[l]!='x')
     {
        s[i] = s[l];
        s[l] = 'x';
        
       return (last(s,n,++i,--l));
     }else {
        return(last(s,n,i,--l));
     }
  
 }else {
   return(last(s,n,++i,l));
 }

//return ans;

}

int main(){
string s,l;
cout<<"Enter string : ";
cin>>s;

cout<<"ans is : "<<last(s,s.length()-1,0,s.length()-1)<<endl;
    return 0;
}