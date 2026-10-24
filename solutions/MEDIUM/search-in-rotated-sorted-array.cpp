// Problem: Search in Rotated Sorted Array
// Difficulty: MEDIUM
// Link: https://leetcode.com/problems/search-in-rotated-sorted-array/
// Approach: Modified binary search that, in each step, determines which half of the current search space is sorted and then checks if the target lies within that sorted half to narrow the search.

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int low = 0;
        int high = nums.size() - 1;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (nums[mid] == target) {
                return mid;
            }

            
            if (nums[low] <= nums[mid]) { 
                if (nums[low] <= target && target < nums[mid]) {
                    
                    high = mid - 1;
                } else {
                    
                    low = mid + 1;
                }
            } else { 
                if (nums[mid] < target && target <= nums[high]) {
                    
                    low = mid + 1;
                } else {
                    
                    high = mid - 1;
                }
            }
        }

        return -1; 
    }
};
