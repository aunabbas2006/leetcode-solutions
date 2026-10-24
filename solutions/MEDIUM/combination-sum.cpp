// Problem: Combination Sum
// Difficulty: MEDIUM
// Link: https://leetcode.com/problems/combination-sum/
// Approach: Backtracking algorithm that recursively explores all combinations by trying each candidate, allowing its re-selection, and adding it to the current path if it does not exceed the target sum. A combination is found when the target sum is exactly zero.

class Solution {
private:
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
            
            
            
            if (candidates[i] > remaining_target) {
                break;
            }
            current_combination.push_back(candidates[i]);
            
            backtrack(candidates, remaining_target - candidates[i], i);
            current_combination.pop_back(); 
        }
    }

public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        result.clear(); 
        current_combination.clear(); 

        
        
        
        
        sort(candidates.begin(), candidates.end());
        
        backtrack(candidates, target, 0);
        return result;
    }
};
