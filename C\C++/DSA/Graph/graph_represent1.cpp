#include<iostream>
#include<vector>

using namespace std;

int main() {

    int N, M, p, q, i, j, w;

    cout << "Enter the number of vertices and edges: ";
    cin >> N >> M;

    vector< vector< pair<int, int> > > g(N);

    cout << "Enter edges with weight: ";

    for (i = 0; i < M; i++) {
        cin >> p >> q >> w;
        g[p - 1].push_back({q - 1, w});
        g[q - 1].push_back({p - 1, w});
    }

    for (i = 0; i < N; i++) {
        cout << "Vertex " << i + 1 << " is connected to: ";
        for (j = 0; j < g[i].size(); j++) {
            cout << "(" << g[i][j].first + 1 << ", " << g[i][j].second << ") ";
        }
        cout << endl;
    }

    return 0;
}
