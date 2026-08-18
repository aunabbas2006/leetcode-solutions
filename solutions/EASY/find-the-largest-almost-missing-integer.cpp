// Problem: Find the Largest Almost Missing Integer
// Difficulty: EASY
// Link: https://leetcode.com/problems/find-the-largest-almost-missing-integer/
// Approach: Use a hash map to store, for each number, a set of the starting indices of subarrays of size k in which it appears. After processing all subarrays, iterate through the map to find the largest number whose corresponding set contains exactly one index.

class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        vector<int> count_subarrays_with_val(51, 0);
        
        vector<bool> val_seen_in_current_subarray(51, false);
        
        int n = nums.size();
        
        for (int i = 0; i <= n - k; ++i) {
            for (int val_idx = 0; val_idx <= 50; ++val_idx) {
                val_seen_in_current_subarray[val_idx] = false;
            }
            
            for (int j = 0; j < k; ++j) {
                int current_val = nums[i + j];
                if (!val_seen_in_current_subarray[current_val]) {
                    count_subarrays_with_val[current_val]++;
                    val_seen_in_current_subarray[current_val] = true;
                }
            }
        }
        
        for (int x = 50; x >= 0; --x) {
            if (count_subarrays_with_val[x] == 1) {
                return x;
            }
        }
        
        return -1;
    }
};
