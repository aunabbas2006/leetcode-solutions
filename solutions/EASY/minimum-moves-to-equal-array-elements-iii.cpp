// Problem: Minimum Moves to Equal Array Elements III
// Difficulty: EASY
// Link: https://leetcode.com/problems/minimum-moves-to-equal-array-elements-iii/
// Approach: Find the maximum element in the array, then calculate the total moves by summing the differences between this maximum and each element.

class Solution {
public:
    int minMoves(vector<int>& nums) {
        int maxVal = 0;
        long long sumNums = 0;

        for (int num : nums) {
            if (num > maxVal) {
                maxVal = num;
            }
            sumNums += num;
        }

        return nums.size() * maxVal - sumNums;
    }
};
