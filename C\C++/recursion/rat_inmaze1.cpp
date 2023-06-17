#include<iostream>
using namespace std;

bool isSafe(int i, int j,int maze[][5],int n){
    if((i<5)&&(j<5)&&(maze[i][j]==1))
    return true;
    else return false;
}

bool rat (int maze[][5], int i, int j, int ans[][5]){

if (i==4 && j==4)
{
    ans[i][j] = 1;
    return true;
}

if (isSafe(i,j,maze,5))
{   
    ans[i][j] = 1;
    if(rat(maze,i+1,j,ans)){
        return true;
    }
    if(rat(maze,i,j+1,ans)){
        return true;
    }
    
    ans[i][j]=0;
    return false;
}
return false;
   
}



int main(){

int i,j,maze[5][5] = {
                   {1,0,1,0,1},
                   {1,1,1,0,1},
                   {0,1,1,1,0},
                   {1,0,0,1,1},
                   {1,1,1,0,1}
                 };
int ans[5][5] = {
                   {0,0,0,0,0},
                   {0,0,0,0,0},
                   {0,0,0,0,0},
                   {0,0,0,0,0},
                   {0,0,0,0,0}
                };
rat(maze,0,0,ans);

for ( i = 0; i < 5; i++)
{
    for ( j = 0; j < 5; j++)
    {
        cout<<ans[i][j]<<" ";
    }
    cout<<endl;
}


    return 0;
}