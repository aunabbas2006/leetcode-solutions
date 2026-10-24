// Problem: Next Permutation
// Difficulty: MEDIUM
// Link: https://leetcode.com/problems/next-permutation/
// Approach: Find the rightmost element `k` such that `nums[k] < nums[k+1]`; if no such `k` exists, reverse the entire array. Otherwise, find the rightmost `l` such that `nums[k] < nums[l]`, swap `nums[k]` and `nums[l]`, then reverse the subarray from `k+1` to the end.

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        if (n <= 1) {
            return;
        }

        
        int k = -1;
        for (int i = n - 2; i >= 0; --i) {
            if (nums[i] < nums[i+1]) {
                k = i;
                break;
            }
        }

        
        
        if (k == -1) {
            int left = 0;
            int right = n - 1;
            while (left < right) {
                int temp = nums[left];
                nums[left] = nums[right];
                nums[right] = temp;
                left++;
                right--;
            }
            return;
        }

        
        int l = -1;
        for (int i = n - 1; i > k; --i) {
            if (nums[i] > nums[k]) {
                l = i;
                break;
            }
        }

        
        int temp = nums[k];
        nums[k] = nums[l];
        nums[l] = temp;

        
        int left = k + 1;
        int right = n - 1;
        while (left < right) {
            temp = nums[left];
            nums[left] = nums[right];
            nums[right] = temp;
            left++;
            right--;
        }
    }
};
