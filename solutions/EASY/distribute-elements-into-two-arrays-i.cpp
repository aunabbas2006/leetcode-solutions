// Problem: Distribute Elements Into Two Arrays I
// Difficulty: EASY
// Link: https://leetcode.com/problems/distribute-elements-into-two-arrays-i/
// Approach: Simulate the process by initializing two arrays with the first two elements from `nums`, then iterate through the remaining elements, appending each to `arr1` or `arr2` based on the comparison of their current last elements, and finally concatenate the two resulting arrays.

class Solution {
public:
    vector<int> resultArray(vector<int>& nums) {
        vector<int> arr1;
        vector<int> arr2;

        arr1.push_back(nums[0]);
        arr2.push_back(nums[1]);

        for (int i = 2; i < nums.size(); ++i) {
            if (arr1.back() > arr2.back()) {
                arr1.push_back(nums[i]);
            } else {
                arr2.push_back(nums[i]);
            }
        }

        arr1.insert(arr1.end(), arr2.begin(), arr2.end());
        return arr1;
    }
};
