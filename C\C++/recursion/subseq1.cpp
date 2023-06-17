#include<iostream>
#include<string>
using namespace std;

void sub(string s, int i, int j){

cout<<s<<endl;

if(i==j-2){
sub(s.substr(0,j),0,j-1);
}

if (s.length()==0)
{
    return;
}



//cout<<s<<endl;

sub(s.substr(i,j),i++,j);


}


int main(){
 string s;
 cout<<"Enter string : ";
 cin>>s;
 sub(s,0,s.length()-1);


    return 0;
}