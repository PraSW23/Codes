//need change
#include<iostream>
using namespace std;

int a[5][5] = {
               {0,0,0,0,0},
               {0,0,0,0,0},
               {0,0,0,0,0},
               {0,0,0,0,0},
               {0,0,0,0,0}     
                    };



void ratmaze(int maze[][5], int i, int j){

if((i>4)&&(j>4)){
    return;
}


if(i<5 && j<5){

if(maze[i][j]==1){

a[i][j] = 1;
}

if(((maze[i+1][j]==0)&&(maze[i][j+1]==0))||((i+1>4)&&(maze[i][j+1]==0))||((maze[i+1][j]==0)&&(j+1>4))){
//cout<<"hell0\n";

a[i][j] = 0;

if(((maze[i-1][j]!=0)&&(i>=0))&&(j<4)){

ratmaze(maze,i-1,j+1);
}else if((maze[i-1][j]!=0)&&(i>=0)){
        ratmaze(maze,i-1,j);
}

if(((maze[i][j-1]!=0)&&(j>=0))&&(i<4)){
ratmaze(maze,i+1,j-1);
}else if((maze[i][j-1]!=0)&&(j>=0)){
ratmaze(maze,i,j-1);
}

}
}


if((maze[i+1][j]!=0)&&(i<4))
ratmaze(maze,i+1,j);
else if((maze[i][j+1]!=0)&&(j<4))
ratmaze(maze,i,j+1);




}


int main(){
int maze[][5] = {
               {1,0,1,0,1},
               {1,1,1,1,1},
               {1,1,0,1,0},
               {1,0,0,1,1},
               {1,1,1,0,1}     
                    };


 ratmaze(maze,0,0);

 for (int i = 0; i < 5; i++)
 {
    for (int j = 0; j < 5; j++)
    {
        cout<<a[i][j]<<" ";
    }
    cout<<endl;
 }
 

    return 0;
}