// Problem: Find X Value of Array I
// Difficulty: MEDIUM
// Link: https://leetcode.com/problems/find-x-value-of-array-i/
// Approach: Dynamic programming iterates from right to left, maintaining counts of product remainders modulo k for all subarrays found in the suffix processed so far, which are then combined with the current element to update the total counts.

class Solution {
public:
    vector<long long> resultArray(vector<int>& nums, int k) {
        int n = nums.size();
        vector<long long> result(k, 0);
        
        vector<long long> current_product_counts(k, 0);
        
        for (int i = 0; i < n; ++i) {
            vector<long long> new_product_counts(k, 0);
            
            int num_val_mod_k = nums[i] % k;
            new_product_counts[num_val_mod_k]++;
            
            for (int rem = 0; rem < k; ++rem) {
                if (current_product_counts[rem] > 0) {
                    long long new_rem = (1LL * rem * nums[i]) % k;
                    new_product_counts[new_rem] += current_product_counts[rem];
                }
            }
            
            for (int r = 0; r < k; ++r) {
                result[r] += new_product_counts[r];
            }
            
            current_product_counts = new_product_counts;
        }
        
        return result;
    }
};
