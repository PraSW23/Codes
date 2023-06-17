#include <iostream>
#include <vector>
#include <stack>

using namespace std;

void DFS(vector<int> *G, int startVertex, int numVertices) {
    vector<bool> visited(numVertices, false);  // Keep track of visited vertices
    stack<int> stack;

    stack.push(startVertex);
    visited[startVertex] = true;

    while (!stack.empty()) {
        int vertex = stack.top();
        stack.pop();
        cout << vertex << endl;

        for (int adjacent : G[vertex]) {
            if (!visited[adjacent]) {
                stack.push(adjacent);
                visited[adjacent] = true;
            }
        }
    }
}

int main() {
    int numVertices, numEdges;

    cout << "Enter the number of vertices: ";
    cin >> numVertices;
    cout << "Enter the number of edges: ";
    cin >> numEdges;

    vector<int> G[numVertices];

    cout << "Enter the edges: " << endl;
    for (int i = 0; i < numEdges; i++) {
        int u, v;
        cin >> u >> v;
        G[u].push_back(v);
        G[v].push_back(u);
    }

    int startVertex;
    cout << "Enter the starting vertex: ";
    cin >> startVertex;

    cout << "DFS Traversal: " << endl;
    DFS(G, startVertex, numVertices);

    return 0;
}
