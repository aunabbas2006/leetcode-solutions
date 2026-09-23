// Problem: Minimum Operations to Reduce X to Zero
// Difficulty: MEDIUM
// Link: https://leetcode.com/problems/minimum-operations-to-reduce-x-to-zero/
// Approach: Sliding window to find the longest contiguous subarray whose sum equals `total_sum - x`, then calculate minimum operations as `nums.length - max_subarray_length`.

class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int n = nums.size();
        long long total_sum = 0;
        for (int num : nums) {
            total_sum += num;
        }

        long long target_sum_for_middle = total_sum - x;

        if (target_sum_for_middle < 0) {
            return -1;
        }

        int max_len = -1;
        long long current_sum = 0;
        int left = 0;

        for (int right = 0; right < n; ++right) {
            current_sum += nums[right];

            while (current_sum > target_sum_for_middle && left <= right) {
                current_sum -= nums[left];
                left++;
            }

            if (current_sum == target_sum_for_middle) {
                max_len = (max_len > (right - left + 1) ? max_len : (right - left + 1));
            }
        }

        if (max_len == -1) {
            return -1;
        } else {
            return n - max_len;
        }
    }
};
