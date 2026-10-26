// Problem: Count Islands With Total Value Divisible by K
// Difficulty: MEDIUM
// Link: https://leetcode.com/problems/count-islands-with-total-value-divisible-by-k/
// Approach: Iterate through the grid, using Depth-First Search (DFS) or Breadth-First Search (BFS) to find connected land cells (islands), summing their values. Mark visited cells during traversal and increment a counter if an island's total value is divisible by k.

class Solution {
public:
    int countIslands(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<bool>> visited(m, vector<bool>(n, false));
        int divisibleIslandsCount = 0;

        int dr[] = {-1, 1, 0, 0}; 
        int dc[] = {0, 0, -1, 1}; 

        for (int r = 0; r < m; ++r) {
            for (int c = 0; c < n; ++c) {
                if (grid[r][c] > 0 && !visited[r][c]) {
                    long long currentIslandSum = 0;
                    queue<pair<int, int>> q;

                    q.push({r, c});
                    visited[r][c] = true;

                    while (!q.empty()) {
                        pair<int, int> curr = q.front();
                        q.pop();
                        int currR = curr.first;
                        int currC = curr.second;

                        currentIslandSum += grid[currR][currC];

                        for (int i = 0; i < 4; ++i) {
                            int nr = currR + dr[i];
                            int nc = currC + dc[i];

                            if (nr >= 0 && nr < m && nc >= 0 && nc < n &&
                                grid[nr][nc] > 0 && !visited[nr][nc]) {
                                visited[nr][nc] = true;
                                q.push({nr, nc});
                            }
                        }
                    }

                    if (currentIslandSum % k == 0) {
                        divisibleIslandsCount++;
                    }
                }
            }
        }

        return divisibleIslandsCount;
    }
};
