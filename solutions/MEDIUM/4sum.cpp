// Problem: 4Sum
// Difficulty: MEDIUM
// Link: https://leetcode.com/problems/4sum/
// Approach: Sort the array, then use nested loops to fix the first two numbers and apply a two-pointer approach on the remaining subarray to find the other two numbers, skipping duplicates at each step.

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> result;
        int n = nums.size();

        if (n < 4) {
            return result;
        }

        sort(nums.begin(), nums.end());

        for (int i = 0; i < n - 3; ++i) {
            if (i > 0 && nums[i] == nums[i-1]) {
                continue;
            }

            
            
            
            if ((long long)nums[i] + nums[i+1] + nums[i+2] + nums[i+3] > target) {
                break;
            }

            
            
            
            if ((long long)nums[i] + nums[n-3] + nums[n-2] + nums[n-1] < target) {
                continue;
            }

            for (int j = i + 1; j < n - 2; ++j) {
                if (j > i + 1 && nums[j] == nums[j-1]) {
                    continue;
                }

                
                if ((long long)nums[i] + nums[j] + nums[j+1] + nums[j+2] > target) {
                    break;
                }

                
                if ((long long)nums[i] + nums[j] + nums[n-2] + nums[n-1] < target) {
                    continue;
                }

                long long currentTarget2 = (long long)target - nums[i] - nums[j];
                int left = j + 1;
                int right = n - 1;

                while (left < right) {
                    long long currentSum = (long long)nums[left] + nums[right];

                    if (currentSum == currentTarget2) {
                        result.push_back({nums[i], nums[j], nums[left], nums[right]});

                        while (left < right && nums[left] == nums[left+1]) {
                            left++;
                        }
                        while (left < right && nums[right] == nums[right-1]) {
                            right--;
                        }
                        left++;
                        right--;
                    } else if (currentSum < currentTarget2) {
                        left++;
                    } else { 
                        right--;
                    }
                }
            }
        }

        return result;
    }
};
