// Problem: Number of Closed Islands
// Difficulty: MEDIUM
// Link: https://leetcode.com/problems/number-of-closed-islands/
// Approach: Perform a flood-fill (DFS/BFS) from all `0`s on the grid boundaries, converting connected `0`s to `1`s to eliminate non-closed islands. Then, iterate through the modified grid, counting and flood-filling each remaining `0` as a closed island.

class Solution {
private:
    int M;
    int N;

    void dfs(vector<vector<int>>& grid, int r, int c) {
        if (r < 0 || r >= M || c < 0 || c >= N || grid[r][c] == 1) {
            return;
        }

        grid[r][c] = 1;

        dfs(grid, r + 1, c);
        dfs(grid, r - 1, c);
        dfs(grid, r, c + 1);
        dfs(grid, r, c - 1);
    }

public:
    int closedIsland(vector<vector<int>>& grid) {
        M = grid.size();
        N = grid[0].size();

        for (int j = 0; j < N; ++j) {
            if (grid[0][j] == 0) {
                dfs(grid, 0, j);
            }
            if (grid[M - 1][j] == 0) {
                dfs(grid, M - 1, j);
            }
        }

        for (int i = 1; i < M - 1; ++i) {
            if (grid[i][0] == 0) {
                dfs(grid, i, 0);
            }
            if (grid[i][N - 1] == 0) {
                dfs(grid, i, N - 1);
            }
        }

        int closedIslandsCount = 0;
        for (int i = 1; i < M - 1; ++i) {
            for (int j = 1; j < N - 1; ++j) {
                if (grid[i][j] == 0) {
                    closedIslandsCount++;
                    dfs(grid, i, j);
                }
            }
        }

        return closedIslandsCount;
    }
};
