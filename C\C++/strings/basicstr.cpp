#include<iostream>
#include<algorithm>
#include<string>
using namespace std;
int main(){
    int s=0;
    string str,str1(3,'n'),s1="hello ",s2="how are you ",s3= s1+s2,s4="yelslo",s6="13465",s7="l";
  //  cin>>str;
    
    //getline(cin,str);
    //cout<<str<<endl;    
    //cout<<str1<<endl;
    cout<<"find at index= "<<s4.find(s7)<<endl;
    cout<<s2.substr(4,12)<<endl;

    s1.append(s2);
    cout<<s1+s2<<endl;
    cout<<s3<<endl;

    while(s!=s1.length()){
      cout<<s1[s]<<endl;
      s++;
    }

    s1.clear(); //clear whole string 
    cout<<"s1 is : "<<s1<<endl;

    cout<<"s2 compared to s1 : "<<s2.compare(s1)<<endl;
    cout<<"s4 compared to s2 : "<<s4.compare(s2)<<endl;
    cout<<"s4 compared to s4 : "<<s4.compare(s4)<<endl;
    

    cout<<s1.empty()<<endl;  //gives 1 if true or empty
    cout<<s2.empty()<<endl;  //gives 0 if false or not empty
   
   cout<<"substring 'you' is found at index : "<<s2.find("you")<<endl;
   
   cout<<s4.insert(5,"w color")<<endl;
   cout<<s2.size()<<endl;
   

   cout<<s2.erase(3,3)<<endl;

   cout<<to_string(s) + "10"<<endl;
   cout<<stoi("123") + 4 <<endl;
   
   
   sort(s4.begin(),s4.end());
   cout<<s4<<endl;

   //sorting in decending order
   sort(s6.begin(),s6.end(),greater<int>());
   cout<<s6<<endl;
   


    return 0;
}