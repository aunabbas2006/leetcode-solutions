// Problem: Removing Minimum and Maximum From Array
// Difficulty: MEDIUM
// Link: https://leetcode.com/problems/removing-minimum-and-maximum-from-array/
// Approach: Find the indices of the minimum and maximum elements. Calculate the deletions for three strategies: removing both from the front, removing both from the back, or removing one from each end, then return the minimum of these three counts.

class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int n = nums.size();

        int min_val = nums[0];
        int max_val = nums[0];
        int min_idx = 0;
        int max_idx = 0;

        for (int i = 0; i < n; ++i) {
            if (nums[i] < min_val) {
                min_val = nums[i];
                min_idx = i;
            }
            if (nums[i] > max_val) {
                max_val = nums[i];
                max_idx = i;
            }
        }
        
        int idx_a = min(min_idx, max_idx);
        int idx_b = max(min_idx, max_idx);

        int deletions_from_front = idx_b + 1;
        int deletions_from_back = n - idx_a;
        int deletions_mixed = (idx_a + 1) + (n - idx_b);

        return min({deletions_from_front, deletions_from_back, deletions_mixed});
    }
};
