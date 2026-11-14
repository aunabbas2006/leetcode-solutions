// Problem: Minimum Positive Sum Subarray
// Difficulty: EASY
// Link: https://leetcode.com/problems/minimum-positive-sum-subarray/
// Approach: Use prefix sums to calculate subarray sums, then employ a sliding window with a sorted data structure (like `SortedList` or `TreeMap`) to efficiently find the minimum positive difference between current and past prefix sums within the valid length range.

class Solution {
public:
    int minimumSumSubarray(vector<int>& nums, int l, int r) {
        int min_positive_sum = 2147483647; 

        int n = nums.size();

        for (int i = 0; i < n; ++i) {
            int current_sum = 0;
            for (int j = i; j < n; ++j) {
                current_sum += nums[j];
                int len = j - i + 1;

                if (len >= l && len <= r) {
                    if (current_sum > 0) {
                        if (current_sum < min_positive_sum) { 
                            min_positive_sum = current_sum;
                        }
                    }
                }

                if (len > r) {
                    break;
                }
            }
        }

        if (min_positive_sum == 2147483647) { 
            return -1;
        } else {
            return min_positive_sum;
        }
    }
};
