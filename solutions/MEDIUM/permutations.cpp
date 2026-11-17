// Problem: Permutations
// Difficulty: MEDIUM
// Link: https://leetcode.com/problems/permutations/
// Approach: Backtracking (Depth-First Search) to build permutations by iteratively choosing unused numbers for each position, and then undoing the choice to explore other branches.

class Solution {
public:
    vector<vector<int>> result;
    vector<int> currentPermutation;
    vector<bool> used;

    void backtrack(const vector<int>& nums) {
        if (currentPermutation.size() == nums.size()) {
            result.push_back(currentPermutation);
            return;
        }

        for (int i = 0; i < nums.size(); ++i) {
            if (!used[i]) {
                currentPermutation.push_back(nums[i]);
                used[i] = true;

                backtrack(nums);

                used[i] = false;
                currentPermutation.pop_back();
            }
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        result.clear();
        currentPermutation.clear();
        used.assign(nums.size(), false);

        backtrack(nums);

        return result;
    }
};
