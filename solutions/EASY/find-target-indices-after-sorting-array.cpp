// Problem: Find Target Indices After Sorting Array
// Difficulty: EASY
// Link: https://leetcode.com/problems/find-target-indices-after-sorting-array/
// Approach: Sort the input array, then iterate through the sorted array, collecting all indices where the element matches the target.

class Solution {
public:
    vector<int> targetIndices(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        
        vector<int> result;
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] == target) {
                result.push_back(i);
            }
        }
        
        return result;
    }
};
