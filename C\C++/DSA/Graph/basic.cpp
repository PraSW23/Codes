#include<iostream>
using namespace std;


int main(){
    
    int N,M,p,q,i,j;

    cout<<"Enter the no of vertices and Edges : ";
    cin>>N>>M;

    int Graph[N][N];
    cout<<"Enter edges : ";

    for(i=0;i<M;i++){
        cin>>p>>q;
        p--;
        q--;
        Graph[p][q] = 1;
        Graph[q][p] = 1;
    }

    for(i=0;i<N;i++){
        for ( j = 0; j < N; j++)
        {
            if(Graph[i][j] == 1){
                continue;
            }
            else{
                Graph[i][j] = 0;
            }
        }
        
    }
    for(i=0;i<N;i++){
        for ( j = 0; j < N; j++)
        {
            cout<<Graph[i][j]<<" ";
        }
        cout<<endl;
    }



    return 0;
}