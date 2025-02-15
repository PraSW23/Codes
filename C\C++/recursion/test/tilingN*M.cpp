#include <iostream>

using namespace std;

// Function to calculate the number of ways to tile the floor
int countWays(int m, int n, int p, int q) {
  // Base cases: If floor size is smaller than tile size, no ways to tile
  if (m < p || n < q) {
    return 0;
  }

  // Create a table to store the number of ways for subproblems
  int dp[m + 1][n + 1];

  // Fill the first row and column with 1 (one way to tile with single tile)
  for (int i = 0; i <= m; i++) {
    dp[i][0] = (i >= p) ? 1 : 0;
  }
  for (int j = 0; j <= n; j++) {
    dp[0][j] = (j >= q) ? 1 : 0;
  }

  // Fill the remaining table using the recurrence relation
  for (int i = 1; i <= m; i++) {
    for (int j = 1; j <= n; j++) {
      // We can either place the tile horizontally or vertically
      dp[i][j] = dp[i - p][j] + dp[i][j - q];
    }
  }

  // Return the number of ways for the entire floor
  return dp[m][n];
}

int main() {
  int m, n, p, q;

  cout << "Enter the dimensions of the floor (m x n): ";
  cin >> m >> n;

  cout << "Enter the dimensions of the tile (p x q): ";
  cin >> p >> q;

  int ways = countWays(m, n, p, q);

  if (ways == 0) {
    cout << "The floor cannot be completely tiled with the given tiles." << endl;
  } else {
    cout << "The number of ways to tile the floor is: " << ways << endl;
  }

  return 0;
}
