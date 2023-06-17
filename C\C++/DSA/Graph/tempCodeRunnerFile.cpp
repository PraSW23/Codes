#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int largestSumCycle(vector<int>& edges) {
    int N = edges.size();
    vector<int> visited(N, 0);  // Array to track visited nodes
    int maxSum = -1;

    for (int i = 0; i < N; i++) {
        if (visited[i] == 0) {
            int start = i;
            int curr = i;
            int sum = 0;
            int cycleLength = 0;

            while (visited[curr] == 0) {
                visited[curr] = 1;
                sum += curr;
                curr = edges[curr];
                cycleLength++;
            }

            if (curr == start && cycleLength > 1) {
                maxSum = max(maxSum, sum);
            }
        }
    }

    return maxSum;
}

int main() {
    int N;
    cin >> N;

    vector<int> edges(N);
    for (int i = 0; i < N; i++) {
        cin >> edges[i];
    }

    int largestCycleSum = largestSumCycle(edges);
    cout << largestCycleSum << endl;

    return 0;
}
