#include <iostream>
#include <vector>

using namespace std;

void DFS(vector<int> *G, int *visited, int i, int k) {
    if (G[i].size() == 0) {
        if (i > 0) {
            i--;
            k++;
        }
        DFS(G, visited, G[i][k] - 1, k);
    }

    for (int j = 0; j < G[i].size(); j++) {
        int vertex = G[i][j];
        if (visited[vertex - 1] != 1) {
            cout << vertex << "\n";
            visited[vertex - 1] = 1;
            DFS(G, visited, vertex - 1, 0);
        }
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

    visited[0] = 1;
    cout << "DFS Traversal: " << 1 << "\n";
    DFS(G, visited, 0, 0);

    return 0;
}
