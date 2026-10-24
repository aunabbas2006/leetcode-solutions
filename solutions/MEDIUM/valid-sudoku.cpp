// Problem: Valid Sudoku
// Difficulty: MEDIUM
// Link: https://leetcode.com/problems/valid-sudoku/
// Approach: Iterate through the 9x9 board, using three arrays of hash sets to track seen digits for each row, column, and 3x3 sub-box. If a digit is encountered that is already present in its corresponding row, column, or sub-box set, the Sudoku is invalid.

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<vector<bool>> row_check(9, vector<bool>(9, false));
        vector<vector<bool>> col_check(9, vector<bool>(9, false));
        vector<vector<bool>> box_check(9, vector<bool>(9, false));

        for (int r = 0; r < 9; ++r) {
            for (int c = 0; c < 9; ++c) {
                if (board[r][c] == '.') {
                    continue;
                }

                int num_idx = board[r][c] - '1';

                if (row_check[r][num_idx]) {
                    return false;
                }
                row_check[r][num_idx] = true;

                if (col_check[c][num_idx]) {
                    return false;
                }
                col_check[c][num_idx] = true;

                int box_idx = (r / 3) * 3 + (c / 3);
                if (box_check[box_idx][num_idx]) {
                    return false;
                }
                box_check[box_idx][num_idx] = true;
            }
        }

        return true;
    }
};
