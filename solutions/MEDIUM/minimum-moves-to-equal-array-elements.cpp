// Problem: Minimum Moves to Equal Array Elements
// Difficulty: MEDIUM
// Link: https://leetcode.com/problems/minimum-moves-to-equal-array-elements/
// Approach: Realize that incrementing `n-1` elements is equivalent to decrementing one element relative to all others. The minimum moves required is therefore the sum of differences between each number and the array's smallest element.

class Solution {
public:
    int minMoves(vector<int>& nums) {
        int minVal = nums[0];
        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i] < minVal) {
                minVal = nums[i];
            }
        }

        long long totalMoves = 0;
        for (int num : nums) {
            totalMoves += (num - minVal);
        }

        return static_cast<int>(totalMoves);
    }
};
