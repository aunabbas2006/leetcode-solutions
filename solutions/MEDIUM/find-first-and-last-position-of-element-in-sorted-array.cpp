// Problem: Find First and Last Position of Element in Sorted Array
// Difficulty: MEDIUM
// Link: https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/
// Approach: Perform two modified binary searches: one to find the leftmost (first) occurrence of the target, and another to find the rightmost (last) occurrence.

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> result = {-1, -1};
        if (nums.empty()) {
            return result;
        }

        int n = nums.size();
        int low, high, mid;

        
        low = 0;
        high = n - 1;
        int firstPos = -1;
        while (low <= high) {
            mid = low + (high - low) / 2;
            if (nums[mid] == target) {
                firstPos = mid;
                high = mid - 1; 
            } else if (nums[mid] < target) {
                low = mid + 1;
            } else { 
                high = mid - 1;
            }
        }
        
        result[0] = firstPos;

        
        
        if (firstPos == -1) {
            return result;
        }

        
        low = 0; 
        high = n - 1;
        int lastPos = -1; 
        while (low <= high) {
            mid = low + (high - low) / 2;
            if (nums[mid] == target) {
                lastPos = mid;
                low = mid + 1; 
            } else if (nums[mid] < target) {
                low = mid + 1;
            } else { 
                high = mid - 1;
            }
        }
        
        result[1] = lastPos;

        return result;
    }
};
