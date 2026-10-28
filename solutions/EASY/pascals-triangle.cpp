// Problem: Pascal's Triangle
// Difficulty: EASY
// Link: https://leetcode.com/problems/pascals-triangle/
// Approach: Iteratively generate each row by starting and ending with 1, and calculating inner elements as the sum of adjacent elements from the preceding row.

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> result;

        for (int i = 0; i < numRows; ++i) {
            
            vector<int> currentRow(i + 1);

            
            currentRow[0] = 1;
            if (i > 0) { 
                currentRow[i] = 1;
            }

            
            
            for (int j = 1; j < i; ++j) {
                currentRow[j] = result[i - 1][j - 1] + result[i - 1][j];
            }

            result.push_back(currentRow);
        }

        return result;
    }
};
