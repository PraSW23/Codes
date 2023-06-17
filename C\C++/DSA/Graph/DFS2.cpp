#include <iostream>
#include <vector>

using namespace std;

void DFS(vector<int> *G, int *visited, int vertex) {
   
    cout<<vertex<<endl;
   visited[vertex-1] = true;

   for(int child : G[vertex-1]){
    if(visited[child-1]==1){
        continue;
    }
     DFS(G,visited,child);
   }
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
    DFS(G, visited, 1);

    return 0;
}
