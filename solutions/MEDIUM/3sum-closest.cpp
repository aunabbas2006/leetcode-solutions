// Problem: 3Sum Closest
// Difficulty: MEDIUM
// Link: https://leetcode.com/problems/3sum-closest/
// Approach: Sort the array, then iterate through each element as the first number. Use a two-pointer approach on the remaining subarray to find the two other numbers that, when summed with the first, yield the closest value to the target, adjusting pointers based on the current sum's relation to the target.

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int n = nums.size();

        sort(nums.begin(), nums.end());

        int closestSum = nums[0] + nums[1] + nums[2];
        int minDiff = abs(closestSum - target);

        for (int i = 0; i < n - 2; ++i) {
            int left = i + 1;
            int right = n - 1;

            while (left < right) {
                int currentSum = nums[i] + nums[left] + nums[right];

                if (currentSum == target) {
                    return target;
                }

                int currentDiff = abs(currentSum - target);

                if (currentDiff < minDiff) {
                    minDiff = currentDiff;
                    closestSum = currentSum;
                }

                if (currentSum < target) {
                    left++;
                } else {
                    right--;
                }
            }
        }

        return closestSum;
    }
};
