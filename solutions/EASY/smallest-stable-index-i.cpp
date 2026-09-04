// Problem: Smallest Stable Index I
// Difficulty: EASY
// Link: https://leetcode.com/problems/smallest-stable-index-i/
// Approach: Precompute prefix maximums and suffix minimums for all indices, then iterate from left to right, checking the instability score for each index until the first stable one is found.

class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n = nums.size();

        vector<int> prefixMax(n);
        prefixMax[0] = nums[0];
        for (int i = 1; i < n; ++i) {
            prefixMax[i] = max(prefixMax[i-1], nums[i]);
        }

        vector<int> suffixMin(n);
        suffixMin[n-1] = nums[n-1];
        for (int i = n - 2; i >= 0; --i) {
            suffixMin[i] = min(suffixMin[i+1], nums[i]);
        }

        for (int i = 0; i < n; ++i) {
            int instabilityScore = prefixMax[i] - suffixMin[i];
            if (instabilityScore <= k) {
                return i;
            }
        }

        return -1;
    }
};
