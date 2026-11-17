// Problem: Jump Game II
// Difficulty: MEDIUM
// Link: https://leetcode.com/problems/jump-game-ii/
// Approach: A greedy algorithm that iteratively finds the maximum reach from all positions within the current jump's scope, incrementing the total jumps each time the current reachable boundary is exhausted.

class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) {
            return 0;
        }

        int jumps = 0;
        int current_reach_end = 0;
        int max_reach = 0;

        for (int i = 0; i < n - 1; ++i) {
            max_reach = (max_reach > i + nums[i] ? max_reach : i + nums[i]);

            if (i == current_reach_end) {
                jumps++;
                current_reach_end = max_reach;
                
                if (current_reach_end >= n - 1) {
                    return jumps;
                }
            }
        }

        return jumps;
    }
};
