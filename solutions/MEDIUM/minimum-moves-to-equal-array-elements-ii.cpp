// Problem: Minimum Moves to Equal Array Elements II
// Difficulty: MEDIUM
// Link: https://leetcode.com/problems/minimum-moves-to-equal-array-elements-ii/
// Approach: Sort the array and calculate the sum of absolute differences of each element from the median element.

class Solution {
public:
    int minMoves2(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        
        int n = nums.size();
        int median = nums[n / 2];
        
        long long totalMoves = 0;
        for (int num : nums) {
            totalMoves += abs(num - median);
        }
        
        return static_cast<int>(totalMoves);
    }
};
