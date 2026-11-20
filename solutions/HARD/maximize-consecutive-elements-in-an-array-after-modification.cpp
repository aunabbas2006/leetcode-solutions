// Problem: Maximize Consecutive Elements in an Array After Modification
// Difficulty: HARD
// Link: https://leetcode.com/problems/maximize-consecutive-elements-in-an-array-after-modification/
// Approach: Sort the array, then use dynamic programming with a hash map where `dp[k]` stores the maximum length of a consecutive sequence ending at `k`. For each number `x` in the sorted array, calculate potential new lengths if `x` becomes `x` (extending `dp[x-1]`) or if `x` becomes `x+1` (extending `dp[x]`), and update `dp[x]` and `dp[x+1]` with the maximum possible lengths.

class Solution {
public:
    int maxSelectedElements(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        map<int, int> dp;
        int max_len = 0;

        for (int num : nums) {
            
            
            
            int len_ending_at_num = dp[num - 1] + 1;

            
            
            
            
            
            int len_ending_at_num_plus_1 = dp[num] + 1;

            
            
            
            
            
            
            
            
            dp[num + 1] = max(dp[num + 1], len_ending_at_num_plus_1);
            
            
            dp[num] = max(dp[num], len_ending_at_num);
            
            
            max_len = max({max_len, dp[num], dp[num + 1]});
        }
        
        return max_len;
    }
};
