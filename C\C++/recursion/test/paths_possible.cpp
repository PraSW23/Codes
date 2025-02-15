#include<iostream>
using namespace std;

int paths(int s, int e){
    
    static int a=0;

    if (s==e && a!=0)
    {
        return 1;
    }
    a++;
    int ans=0;
    for (int i = 1; i <= 6; i++)
    {   
        if(s+i <= e)
        ans += paths(s+i, e);
    }
    
    return ans;
}


int main(){
    int s, e;
    cout<<"Enter the starting and ending points : ";
    cin>>s>>e;
    cout<<"No of paths are : "<<paths(s,e)<<endl;
    return 0;
}