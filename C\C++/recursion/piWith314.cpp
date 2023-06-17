#include<iostream>
#include<string>
using namespace std;

void pi(string s, int n, int i){

    if (i==n)
    {   
        return;
    }
    else if(i+2 <= n){
     if ((s[i]=='p')&&(s[i+1]=='i'))
    {
        cout<<"3.14";
    }else {
        cout<<s[i];
        if((n-i)>2){
        if ((s[i+1]!='p')&&(s[i+2]!='i'))
        {
            cout<<s[i+1];
        }
        }
        else if (s[i+1]!='p')
        {
           cout<<s[i+1];
        }
   
    }
    }else if (i+1<=n)
    {
        if ((s[i]=='p')&&(s[i+1]=='i'))
    {
        cout<<"3.14";
    }else {
        cout<<s[i]<<s[i+1];
    }
    }
    else cout<<s[i];

    if (i+2 <= n)
    {
       i =i+2;   
    }
    else i = i+1;
    return pi(s,n,i);
}


int main(){
string s;
cout<<"Enter string : ";
cin>>s;
pi(s,s.length()-1,0);
cout<<endl;

    return 0;
}