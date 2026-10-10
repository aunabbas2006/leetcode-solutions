// Problem: Minimum Sum of Squared Difference
// Difficulty: MEDIUM
// Link: https://leetcode.com/problems/minimum-sum-of-squared-difference/
// Approach: Use a frequency map or max-priority queue to store the absolute differences `|nums1[i] - nums2[i]|`. Greedily reduce the largest differences by one until all `k1 + k2` modifications are exhausted, then calculate the sum of squares of the remaining differences.

class Solution {
public:
    long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2, int k1, int k2) {
        int n = nums1.size();
        long long k_total = (long long)k1 + k2;

        vector<int> diff_counts(100001, 0); 
        int max_abs_diff = 0;

        for (int i = 0; i < n; ++i) {
            int d = abs(nums1[i] - nums2[i]);
            diff_counts[d]++;
            if (d > max_abs_diff) {
                max_abs_diff = d;
            }
        }

        for (int d = max_abs_diff; d >= 1; --d) {
            if (k_total == 0) {
                break;
            }
            if (diff_counts[d] == 0) {
                continue;
            }

            long long num_items_at_d = diff_counts[d];

            if (k_total >= num_items_at_d) {
                k_total -= num_items_at_d;
                diff_counts[d-1] += num_items_at_d;
                diff_counts[d] = 0;
            } else {
                diff_counts[d-1] += k_total;
                diff_counts[d] -= k_total;
                k_total = 0;
                break;
            }
        }

        long long total_sum_sq_diff = 0;
        for (int d = 0; d <= max_abs_diff; ++d) {
            if (diff_counts[d] > 0) {
                total_sum_sq_diff += (long long)diff_counts[d] * d * d;
            }
        }

        return total_sum_sq_diff;
    }
};
