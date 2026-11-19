// Problem: Minimum Score by Changing Two Elements
// Difficulty: MEDIUM
// Link: https://leetcode.com/problems/minimum-score-by-changing-two-elements/
// Approach: Sort the array, then the minimum low score can always be 0 by changing two elements to be identical. Thus, find the minimum high score by considering three cases: effectively removing the two smallest, two largest, or one smallest and one largest element.

class Solution {
public:
    int minimizeSum(vector<int>& nums) {
        int n = nums.size();

        
        sort(nums.begin(), nums.end());

        
        
        
        
        
        
        

        
        
        
        

        
        
        
        int option1 = nums[n-1] - nums[2];

        
        
        
        int option2 = nums[n-3] - nums[0];

        
        
        
        int option3 = nums[n-2] - nums[1];

        
        
        return min({option1, option2, option3});
    }
};
