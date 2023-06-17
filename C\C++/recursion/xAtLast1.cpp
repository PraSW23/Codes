#include<iostream>
#include<string>
using namespace std;

string last(string s, int i, int l){
 if((i==l)||(i>l))
    return s;

 if(s[i]=='x'){
     if (s[l]!='x')
     {   s.erase(i,1);
         s.insert(l,"x");
        //s[i] = s[l];
        //s[l] = 'x';
        
       return (last(s,i,--l));
     }else {
        return(last(s,i,--l));
     }
 }else {
   return(last(s,++i,l));
 }

}

int main(){
string s,l;
cout<<"Enter string : ";
cin>>s;
cout<<"x at last : "<<last(s,0,s.length()-1)<<endl;
    return 0;
}