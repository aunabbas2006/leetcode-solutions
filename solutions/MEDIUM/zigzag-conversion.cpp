// Problem: Zigzag Conversion
// Difficulty: MEDIUM
// Link: https://leetcode.com/problems/zigzag-conversion/
// Approach: Iterate through the string, appending each character to its current row string. Maintain a direction variable to move downwards until the last row is reached, then switch to move upwards until the first row is reached, cycling this pattern. Finally, concatenate all row strings.

class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1) {
            return s;
        }

        vector<string> rows(numRows);
        int curRow = 0;
        int direction = 1; 

        for (char c : s) {
            rows[curRow].push_back(c);

            if (curRow == 0) {
                direction = 1;
            } else if (curRow == numRows - 1) {
                direction = -1;
            }
            curRow += direction;
        }

        string result = "";
        for (const string& row : rows) {
            result += row;
        }

        return result;
    }
};
