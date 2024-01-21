#include <iostream>
#include <string>
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
    
    ans = ans + rem_dup(name.substr(1));

    int is = ans.find(ch);
    if (is < 0 || is > ans.length())
    {
        ans.insert(0,(""+ch));
        //ans.push_back(ch);
        cout<<ans<<endl;

    }
    return ans;
}

int main()
{
    string name;
    cout << "Enter string : ";
    cin >> name;

    name = rem_dup(name);
    cout << name << endl;

    return 0;
}