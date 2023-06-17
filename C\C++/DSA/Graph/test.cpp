#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

// Structure to represent a cell in the grid
struct Cell {
    int row;
    int col;
    int effort;

    Cell(int r, int c, int e) : row(r), col(c), effort(e) {}
};

// Custom comparator for the priority queue based on effort
struct CompareCells {
    bool operator()(const Cell& a, const Cell& b) {
        return a.effort > b.effort;
    }
};

int minimumEffortPath(vector<vector<int>>& heights) {
    int rows = heights.size();
    int cols = heights[0].size();

    // Initialize the minimum efforts grid with maximum values
    vector<vector<int>> minEffort(rows, vector<int>(cols, INT_MAX));

    // Dijkstra's algorithm using a priority queue
    priority_queue<Cell, vector<Cell>, CompareCells> pq;

    // Start from the top-left cell with an effort of 0
    pq.push(Cell(0, 0, 0));
    minEffort[0][0] = 0;

    // Possible directions: up, down, left, right
    vector<int> dr = {-1, 1, 0, 0};
    vector<int> dc = {0, 0, -1, 1};

    while (!pq.empty()) {
        Cell curr = pq.top();
        pq.pop();

        // Check if reached the bottom-right cell
        if (curr.row == rows - 1 && curr.col == cols - 1) {
            return curr.effort;
        }

        // Explore all possible neighbors
        for (int i = 0; i < 4; i++) {
            int newRow = curr.row + dr[i];
            int newCol = curr.col + dc[i];

            // Check if the neighbor is within the grid
            if (newRow >= 0 && newRow < rows && newCol >= 0 && newCol < cols) {
                // Calculate the new effort
                int newEffort = max(curr.effort, abs(heights[curr.row][curr.col] - heights[newRow][newCol]));

                // If the new effort is smaller, update the minimum efforts grid and enqueue the neighbor
                if (newEffort < minEffort[newRow][newCol]) {
                    minEffort[newRow][newCol] = newEffort;
                    pq.push(Cell(newRow, newCol, newEffort));
                }
            }
        }
    }

    return -1;  // No path found
}

int main() {
    vector<vector<int>> heights = {{1, 2,1,1,1}, {1,2,1,2,1}, {1,2,1,2,1,2,1},{1,1,1,2,1}};

    int minEffort = minimumEffortPath(heights);
    cout << "Minimum effort path: " << minEffort << endl;

    return 0;
}
