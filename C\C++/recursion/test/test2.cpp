#include <iostream>
#include <string>
#include <vector>
using namespace std;

string rev(string names)
{

    string ans = "";
    if (names.length() == 1)
    {
        return names;
    }
    char ch = names[0];
    ans = ans + rev(names.substr(1));

    return (ans + ch);
}

void TOH(int n, char A, char B, char C)
{

    if (n == 0)
    {
        return;
    }

    TOH(n - 1, A, C, B);
    cout << "Move Disk from " << A << " to " << C << endl;
    TOH(n - 1, B, A, C);
}

string rem_dup(string name)
{
    string ans = "";
    if (name.length() == 0)
    {
        return ans;
    }
    char ch = name[0];
    
    ans += rem_dup(name.substr(1));

    int is = ans.find(ch);
    if (is == string::npos)  // if (is < 0 || is > ans.length()) also be used
    {
        ans.insert(0, string(1, ch));
        //ans.push_back(ch);

    }
    return ans;
}

string X_at_last(string name){

    if (name.length()==0)
    {
        return "";
    }

    string ans1="", ans2="", ans3="";

    if (name[0] == 'x' || name[0] == 'X')
    {
        ans2.push_back(name[0]);

    }else
    {
        ans1.push_back(name[0]);
    }
    ans3 = ans1 + X_at_last(name.substr(1)) + ans2;
    return (ans3);

}

void substrings(string name){

    if (name.length()==0)
    {
        return;
    }
    cout<<name<<endl;
    for (int i = 0; i < name.length(); i++)
    {
        substrings(name.substr(i,name.length()-1));
    }
    
    
}

void substrings1(string name, string ans = ""){

    if (name.length()==0)
    {
        cout<<ans<<endl;
        return;
    }

    char ch = name[0];

    substrings1(name.substr(1), ans);
    substrings1(name.substr(1), ans + ch);

    
}

void mobile_no(int x, int y, int p=0, int q=0){ 

    const string num[10] = {"","./","abc","def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

     if (p >= num[x].length() || q >= num[y].length())
    {
        return;
    }
    char ch1 = num[x][p];
    char ch2 = num[y][q];

    cout<<ch1<<ch2<<endl;

    mobile_no(x,y,p+1,q);
    mobile_no(x,y,p,q+1);
    
}

void keypad(string s1,string s2,string ans){

const string num[10] = {"","./","abc","def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

if(s1.length()==0 || s2.length()==0){
   if(s2.length()==0){
   s2 = ans;
   keypad(s1.substr(1),s2,ans);
   }
    return;
}
cout<<s1[0]<<s2[0]<<endl;
ans = ans+s2[0];
keypad(s1,s2.substr(1),ans);

}

void permu(string s, string ans=""){

    if (s.length() == 0)
    {
        cout<<ans<<endl;
        return;
    }
    
    for (int i = 0; i < s.length(); i++)
    {
        char ch = s[i];
        permu(s.substr(0,i)+ s.substr(i+1), ans + ch);
    }
    
    

}

int possible_ways(int j, int s=0){

    if (j == 0)
    {
        return 0;
    }

    if (s == j)
    {
        return 1;
    }

    int ans=0;
    for (int i = 1; i <= 6; i++)
    {
        if (s+i <= j)
        {
            ans += possible_ways(j, s+i);
        }
        
    }
    
    return ans;
}

int possible_ways_maze(int n, int i=0, int j=0){

    if (i == n-1 && j == n-1)
    {   
        return 1;
    }

    int ans=0;

    if (i+1 < n)
    {
        ans += possible_ways_maze(n, i+1, j);
    }

    if (j+1 < n)
    {
        ans += possible_ways_maze(n, i, j+1);
    }
    
    return ans;
    
}
/*
bool check(vector <vector <int>> * arr){

    for (int i = 0; i < arr; i++)
    {
        
    }
    

}

int tile_ways(vector <vector <int>> * arr , int i, int j){

    if (m == 0 && n == 0)
    {
        return 1;
    }
    
    if (m < i && m < j)
    {
        return 0;
    }
    
    return tile_ways(m - i, n - j, i, j) + tile_ways(m - j, n - i, i, j);


}
*/

int friends_pair(int n, int s = 0, int p = 0){

    if (p + s == n)
    {
        return 1;
    }

    if (p + s > n)
    {
        return 0;
    }
    

    return friends_pair(n, s+1, p) + (n-(s+p+1))*friends_pair(n, s, p+2);
    

}

int main()
{
    // string name;
    // cout << "Enter string : ";
    // cin >> name;

    // name = X_at_last(name);
    // cout << name << endl;

    //substrings(name);

    int x,y,i,j;
    cout<<"Enter values of X and Y : ";
    cin>>x;

    // mobile_no(x,y);
    //permu(name);
    // vector <vector <int>> arr(x,y,0);
    cout<<friends_pair(x)<<endl;


    return 0;
}