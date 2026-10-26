// Problem: Count Islands With Total Value Divisible by K
// Difficulty: MEDIUM
// Link: https://leetcode.com/problems/count-islands-with-total-value-divisible-by-k/
// Approach: Use Depth-First Search (DFS) or Breadth-First Search (BFS) to traverse the grid. For each unvisited land cell, initiate a traversal to find its connected island, sum its values, mark visited cells, and increment a counter if the total sum is divisible by k.

class Solution {
public:
    int countIslands(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<bool>> visited(m, vector<bool>(n, false));
        int islandCount = 0;

        int dr[] = {-1, 1, 0, 0}; 
        int dc[] = {0, 0, -1, 1}; 

        for (int r = 0; r < m; ++r) {
            for (int c = 0; c < n; ++c) {
                if (grid[r][c] > 0 && !visited[r][c]) {
                    long long currentIslandSum = 0; 

                    stack<pair<int, int>> s;
                    s.push({r, c});
                    visited[r][c] = true;

                    while (!s.empty()) {
                        pair<int, int> current = s.top();
                        s.pop();
                        int curr_r = current.first;
                        int curr_c = current.second;

                        currentIslandSum += grid[curr_r][curr_c];

                        for (int i = 0; i < 4; ++i) {
                            int nr = curr_r + dr[i];
                            int nc = curr_c + dc[i];

                            if (nr >= 0 && nr < m && nc >= 0 && nc < n &&
                                grid[nr][nc] > 0 && !visited[nr][nc]) {
                                visited[nr][nc] = true;
                                s.push({nr, nc});
                            }
                        }
                    }

                    if (currentIslandSum % k == 0) {
                        islandCount++;
                    }
                }
            }
        }
        return islandCount;
    }
};
