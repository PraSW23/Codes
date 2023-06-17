#include <iostream>
#include <vector>

using namespace std;
bool test = false;
bool DFS(vector<int> *G, int *visited, int vertex) {
   
   visited[vertex-1] = true;
   int parent = vertex;
   for(int child : G[vertex-1]){
    if(visited[child-1]==1 && parent == child){
        continue;
    }
    if(visited[child -1]==1){
        test = true;
        return true;
    }
    //int curr_vertex = child;
     DFS(G,visited,child);
    //  if(curr_vertex == vertex){
    //     return true;
    //  }
   }
    return test;
}

int main() {
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

    // visited[0] = 1;
    // cout << "DFS Traversal: " << 1 << "\n";
    if(DFS(G, visited, 1)){
        cout<<"Cycle found"<<endl;
    }
    else cout<<"Cycle not found"<<endl;

    return 0;
}
