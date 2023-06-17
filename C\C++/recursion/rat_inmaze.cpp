#include<iostream>
using namespace std;




void rat (int maze[][5], int i, int j, int ans[][5]){


if ((i>4)||(j>4))
{ 
    return;
}
ans[i][j]=1;

if(((maze[i+1][j]==0)&&(maze[i][j+1]==0))||((i+1==5)&&(maze[i][j+1]==0))||((maze[i+1][j]==0)&&(j+1==5))){

ans[i][j]=0;

if(maze[i-1][j]==0)
rat(maze,i+1,j-1,ans);


if(maze[i-1][j+1]==0)
rat(maze,i+1,j-1,ans);

rat(maze, i-1,j+1,ans);
    
}

if(i)

if((maze[i+1][j]!=0)&&(i<4))
rat(maze,i+1,j,ans);
else if((maze[i][j+1]!=0)&&(j<4))
rat(maze,i,j+1,ans);



}





int main(){

int i,j,maze[5][5] = {
                   {1,0,1,0,1},
                   {1,1,1,1,1},
                   {0,1,0,1,0},
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