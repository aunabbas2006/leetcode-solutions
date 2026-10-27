// Problem: Create Grid With Exactly One Path
// Difficulty: EASY
// Link: https://leetcode.com/problems/create-grid-with-exactly-one-path/
// Approach: Construct a unique L-shaped path from top-left to bottom-right by marking all cells in the first row and the last column as free, and all other cells as obstacles.

class Solution {
public:
    vector<string> createGrid(int m, int n) {
        vector<string> grid(m, string(n, '#'));

        for (int c = 0; c < n; ++c) {
            grid[0][c] = '.';
        }

        for (int r = 1; r < m; ++r) {
            grid[r][n - 1] = '.';
        }

        return grid;
    }
};
