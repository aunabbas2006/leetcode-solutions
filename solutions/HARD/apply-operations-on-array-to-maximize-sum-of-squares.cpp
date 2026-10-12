// Problem: Apply Operations on Array to Maximize Sum of Squares
// Difficulty: HARD
// Link: https://leetcode.com/problems/apply-operations-on-array-to-maximize-sum-of-squares/
// Approach: The bitwise operation preserves the total count of set bits for each position across the array. Therefore, count the global occurrences of each bit and then greedily construct `k` numbers by setting the `p`-th bit in the first `count_p` numbers to maximize their sum of squares.

class Solution {
public:
    int maxSum(vector<int>& nums, int k) {
        vector<int> bit_counts(30, 0);

        for (int num : nums) {
            for (int p = 0; p < 30; ++p) {
                if ((num >> p) & 1) {
                    bit_counts[p]++;
                }
            }
        }

        vector<long long> final_k_nums(k, 0);

        for (int p = 0; p < 30; ++p) {
            int num_ones_for_this_bit = bit_counts[p];
            int ones_to_distribute = min(k, num_ones_for_this_bit);
            
            for (int i = 0; i < ones_to_distribute; ++i) {
                final_k_nums[i] = final_k_nums[i] | (1LL << p);
            }
        }

        long long total_sum_sq = 0;
        long long MOD = 1e9 + 7;

        for (long long num_val : final_k_nums) {
            long long square = (num_val * num_val) % MOD;
            total_sum_sq = (total_sum_sq + square) % MOD;
        }

        return static_cast<int>(total_sum_sq);
    }
};
