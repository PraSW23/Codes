#include<iostream>
using namespace std;

int paths(int s, int e, int n, int m){
    
    if (s == n && e == m)
    {
        return 1;
    }else if (s>n || e>m)
    {
        return 0;
    }
    

    int path = paths(s+1, e, n, m) + paths(s, e+1, n, m);
    return path;
    
}


int main(){
    int s, e, n, m;
    cout<<"Enter the starting and ending points and maze size: ";
    cin>>s>>e>>n>>m;
    cout<<"No of paths are : "<<paths(s,e, n, m)<<endl;
    return 0;
}