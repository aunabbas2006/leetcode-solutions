// Problem: Count Servers that Communicate
// Difficulty: MEDIUM
// Link: https://leetcode.com/problems/count-servers-that-communicate/
// Approach: First, count the number of servers in each row and column. Then, iterate through the grid, and for each server, if its corresponding row count or column count is greater than one, increment the total count of communicating servers.

class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<int> row_counts(m, 0);
        vector<int> col_counts(n, 0);

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 1) {
                    row_counts[i]++;
                    col_counts[j]++;
                }
            }
        }

        int communicating_servers_count = 0;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 1) {
                    if (row_counts[i] > 1 || col_counts[j] > 1) {
                        communicating_servers_count++;
                    }
                }
            }
        }

        return communicating_servers_count;
    }
};
