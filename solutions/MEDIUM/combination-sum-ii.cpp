// Problem: Combination Sum II
// Difficulty: MEDIUM
// Link: https://leetcode.com/problems/combination-sum-ii/
// Approach: Backtracking (Depth-First Search) is used to explore all combinations, with candidates sorted initially. To avoid duplicate combinations and ensure each number is used at most once, during recursion, elements are considered from the next index, and identical adjacent elements are skipped.

class Solution {
public:
    vector<vector<int>> result;
    vector<int> current_combination;

    void backtrack(const vector<int>& candidates, int remaining_target, int start_index) {
        if (remaining_target == 0) {
            result.push_back(current_combination);
            return;
        }

        if (remaining_target < 0) {
            return;
        }

        for (int i = start_index; i < candidates.size(); ++i) {
            if (i > start_index && candidates[i] == candidates[i-1]) {
                continue;
            }

            if (candidates[i] > remaining_target) {
                break;
            }

            current_combination.push_back(candidates[i]);
            backtrack(candidates, remaining_target - candidates[i], i + 1);
            current_combination.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());

        result.clear();
        current_combination.clear();
        
        backtrack(candidates, target, 0);
        
        return result;
    }
};
