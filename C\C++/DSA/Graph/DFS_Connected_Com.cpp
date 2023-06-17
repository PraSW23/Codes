#include<iostream>
#include<vector>

using namespace std;


void DFS(vector<int> * G, int * visited, int vertex){

    visited[vertex-1] = 1;

    for(int i: G[vertex-1]){
        if(visited[i-1]==1){
            continue;
        }
        DFS(G,visited,i);
    }
}


int Connnected_component(vector<int>*G, int * visited, int N){

int count=0;
 for (int i = 0; i < N; i++)
 {
        if (visited[i]!=1)
        {   count++;
            DFS(G,visited,i+1);
        }
        
    
 }
 
return count;

}

int main(){

    int N, M, i, j, p, q;

    cout << "Enter Vertices and Edges of Graph: ";
    cin >> N >> M;

    int visited[N];
    vector<int> G[N];

    cout << "Enter Edges: ";

    for (i = 0; i < M; i++) {
        cin >> p >> q;
        G[p - 1].push_back(q);
        G[q - 1].push_back(p);
    }

    
    cout<<"connected Component are : "<<Connnected_component(G, visited, N)<<endl;

    return 0;
}