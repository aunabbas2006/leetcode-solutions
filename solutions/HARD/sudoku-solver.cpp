// Problem: Sudoku Solver
// Difficulty: HARD
// Link: https://leetcode.com/problems/sudoku-solver/
// Approach: Recursive backtracking algorithm that iterates through empty cells, attempts to place digits 1-9, validates placements against Sudoku rules, and backtracks if a placement doesn't lead to a solution.

class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        backtrack(board, 0, 0);
    }

private:
    bool isValid(vector<vector<char>>& board, int row, int col, char val) {
        for (int j = 0; j < 9; ++j) {
            if (board[row][j] == val) {
                return false;
            }
        }

        for (int i = 0; i < 9; ++i) {
            if (board[i][col] == val) {
                return false;
            }
        }

        int startRow = (row / 3) * 3;
        int startCol = (col / 3) * 3;
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                if (board[startRow + i][startCol + j] == val) {
                    return false;
                }
            }
        }

        return true;
    }

    bool backtrack(vector<vector<char>>& board, int r, int c) {
        if (r == 9) {
            return true;
        }

        if (c == 9) {
            return backtrack(board, r + 1, 0);
        }

        if (board[r][c] != '.') {
            return backtrack(board, r, c + 1);
        }

        for (char num_char = '1'; num_char <= '9'; ++num_char) {
            if (isValid(board, r, c, num_char)) {
                board[r][c] = num_char;

                if (backtrack(board, r, c + 1)) {
                    return true;
                }

                board[r][c] = '.'; 
            }
        }

        return false;
    }
};
