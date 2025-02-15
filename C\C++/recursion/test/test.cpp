#include <iostream>
#include <string>
using namespace std;

// reverse
string reverse(string str, string ans, int n)
{
    if (str.length() == 0)
    {
        return str;
    }
    if (n == ans.length())
    {
        return ans;
    }
    reverse(str.substr(1), ans, n);
    ans = ans + str[0];
}

// piwith3.14
string rplace(string s, int i)
{

    if ((s[i] == 'p') && (s[i + 1] == 'i'))
    {
        s.erase(i, 2);
        s.insert(i, "3.14");
    }
    if (i != s.length() - 1)
    {
        s = rplace(s, ++i);
    }
    return s;
}

// tower of hanoi
void tow(char A, char C, char B, int n)
{

    if (n == 0)
    {
        return;
    }

    tow(A, B, C, n - 1);
    cout << "Moving disk from " << A << " to " << C << endl;
    tow(B, C, A, n - 1);
}

// remdup
void remdup(string s)
{
    if (s.length() == 0)
    {
        cout << endl;
        return;
    }
    cout << s[0];

    for (int i = 1; i < s.length(); i++)
    {
        if (s[i] == s[0])
        {
            s.erase(i, 1);
            i -= 1;
        }
    }
    remdup(s.substr(1));
}

// x at last
void xatlast(string s, string ans,int i)
{

    if (i == s.length())
    {
        cout << s+ans;
        return;
    }
    if (s[i] == 'x')
    {
        s.erase(i, 1);
        ans.push_back('x');
        --i;
    }
    xatlast(s,ans,++i);
}

string xatlast2(string s, string ans)
{

    if (0 == s.length())
    {
        return "";
    }
   
    char ch = s[0];
     
     ans = xatlast2(s.substr(1),ans);

    if(ch=='x'){
      return ans+ch;
    }
    else return ch+ans;

}

//subseq
void subseq(string s,string ans){
    
  if(s.length()==0){
   // int x = stoi(ans);
    cout<<ans<<endl;
    return;

  }

 char ch = s[0];
 int c = ch;
 string ab = to_string(c);
 subseq(s.substr(1),ans);
 subseq(s.substr(1),ans+ch);
 subseq(s.substr(1),ans+ab);

}

//mobilekeyCombination
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

//all possible permutation
void permuall(string s1, string ans,int i){
if(s1.length() <= i){
    cout<<ans<<endl;
    ans = "";
    return;
}
permuall(s1,ans,i+1);
permuall(s1,ans+s1[i],i+1);
permuall(s1,s1[i]+ans,i+1);

}

//permutation
void permu(string s1, string ans){

if(s1.length()==2){
    char temp = s1[0];
    s1[0] = s1[1];
    s1[1] = temp;
    permu(s1+ans,"");

    return;
}
cout<<s1<<endl;
ans = ans + s1[0];
permu(s1.substr(1),ans);

}
int t=0;
void permu2(string s, string ans){
  
  if((s.length()==0) || (t==ans.length())){
    return;
  }
  cout<<s<<endl;
  if(s.length()==2){
    swap(s[0],s[1]);
    t++;
    string c = ""+ans[0];
   ans.insert(ans.length()-1,c);
   ans.erase(0,1);
   s = ans;
   permu2(ans,ans);
    return;

  }
  
   permu2(s.substr(1),ans);

}


int main()
{
    string str;
   // string s[]={"","./","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
  //  int n1,n2;
    cout << "Enter string to : ";
    cin >> str;
    //cout<<"Enter numbers : ";
   // cin>>n1>>n2;
    // cout<<endl<<"Reversed string is : "<<reverse(str,"",str.length());
    // cout<<rplace(str,0);
    // tow('A','C','B',n);
    // remdup(str);
    // cout<<ans;
    // cout<<
    //xatlast(str,"",0);
   // cout<<xatlast2(str,"");
   subseq(str,"");
// keypad(s[n1],s[n2],"");
   //permu2(str,str);
 
    return 0;
}