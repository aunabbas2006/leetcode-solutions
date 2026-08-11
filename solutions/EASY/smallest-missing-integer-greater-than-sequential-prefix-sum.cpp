// Problem: Smallest Missing Integer Greater Than Sequential Prefix Sum
// Difficulty: EASY
// Link: https://leetcode.com/problems/smallest-missing-integer-greater-than-sequential-prefix-sum/
// Approach: First, calculate the sum of the longest sequential prefix starting from `nums[0]`. Then, starting from this sum, iterate upwards and check against a hash set of `nums` to find the smallest integer not present in the array.

class Solution {
public:
    int missingInteger(vector<int>& nums) {
        
        
        int prefixSum = nums[0]; 
        for (int i = 1; i < nums.size(); ++i) {
            
            if (nums[i] == nums[i-1] + 1) {
                prefixSum += nums[i];
            } else {
                
                break; 
            }
        }

        
        
        
        unordered_set<int> presentNums;
        for (int num : nums) {
            presentNums.insert(num);
        }

        
        int x = prefixSum; 
        while (true) { 
            
            
            
            if (presentNums.find(x) == presentNums.end()) {
                
                
                return x;
            }
            x++; 
        }
    }
};
