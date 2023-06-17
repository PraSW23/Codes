#include <iostream>
#include <vector>
#include <queue>
#include <unordered_set>

using namespace std;

int findNearestMeetingCell(vector<vector<int>>& edges, int src, int dest) {
    int n = edges.size();
    
    vector<bool> visited(n, false);
    queue<int> q1, q2;
    
    q1.push(src);
    q2.push(dest);
    visited[src] = true;
    visited[dest] = true;
    
    while (!q1.empty() && !q2.empty()) {
        int size1 = q1.size();
        int size2 = q2.size();
        
        for (int i = 0; i < size1; i++) {
            int curr = q1.front();
            q1.pop();
            
            if (visited[curr] == 2) {
                return curr;
            }
            
            for (int neighbor : edges[curr]) {
                if (!visited[neighbor]) {
                    visited[neighbor] = 1;
                    q1.push(neighbor);
                } else if (visited[neighbor] == 2) {
                    return neighbor;
                }
            }
        }
        
        for (int i = 0; i < size2; i++) {
            int curr = q2.front();
            q2.pop();
            
            if (visited[curr] == 1) {
                return curr;
            }
            
            for (int neighbor : edges[curr]) {
                if (!visited[neighbor]) {
                    visited[neighbor] = 2;
                    q2.push(neighbor);
                } else if (visited[neighbor] == 1) {
                    return neighbor;
                }
            }
        }
    }
    
    return -1; // No meeting cell found
}

int main() {
    int T;
    cin >> T;
    
    while (T--) {
        int N;
        cin >> N;
        
        vector<vector<int>> edges(N);
        for (int i = 0; i < N; i++) {
            int val;
            cin >> val;
            if (val != -1) {
                edges[i].push_back(val);
            }
        }
        
        int src, dest;
        cin >> src >> dest;
        
        int nearestMeetingCell = findNearestMeetingCell(edges, src, dest);
        cout << nearestMeetingCell << endl;
    }
    
    return 0;
}
