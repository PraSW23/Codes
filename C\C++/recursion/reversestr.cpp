#include<iostream>
#include<string>
using namespace std;

void revst(string s){
    int i = s.length()-1;
    
    cout<<s[i];

    if (i==0)
    {
        return;
    }

    return revst(s.erase(s.length()-1,1));
}


int main(){
string s;
cout<<"Enter string to reverse : ";
 getline ( cin ,s);
revst(s);
cout<<endl;

    return 0;
}