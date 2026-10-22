// Problem: Minimum Operations to Sort a Permutation
// Difficulty: MEDIUM
// Link: https://leetcode.com/problems/minimum-operations-to-sort-a-permutation/
// Approach: Check if the input array can be transformed into `[0,1,...,n-1]` through only rotations, or if its reverse can, or if the array itself can be rotated to `[n-1,n-2,...,0]` then reversed. Determine the minimum rotations and at most one reverse operation for these three potential paths.

class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();

        if (n == 1) {
            return 0;
        }

        for (int i = 0; i < n; ++i) {
            int val1 = nums[i];
            int val2 = nums[(i + 1) % n];
            bool condition1 = ((val1 + 1) % n == val2);
            bool condition2 = ((val2 + 1) % n == val1);
            if (!condition1 && !condition2) {
                return -1;
            }
        }

        queue<pair<pair<int, bool>, int>> q;
        map<pair<int, bool>, int> visited;

        bool initial_is_forward = ((nums[0] + 1) % n == nums[1]);
        pair<int, bool> initial_state = {nums[0], initial_is_forward};

        q.push({initial_state, 0});
        visited[initial_state] = 0;

        pair<int, bool> target_state = {0, true};

        while (!q.empty()) {
            pair<pair<int, bool>, int> current = q.front();
            q.pop();

            pair<int, bool> current_state = current.first;
            int ops = current.second;

            if (current_state == target_state) {
                return ops;
            }

            
            pair<int, bool> next_state_rot;
            if (current_state.second) { 
                next_state_rot = {(current_state.first + 1) % n, true};
            } else { 
                next_state_rot = {(current_state.first - 1 + n) % n, false};
            }

            if (visited.find(next_state_rot) == visited.end()) {
                visited[next_state_rot] = ops + 1;
                q.push({next_state_rot, ops + 1});
            }

            
            pair<int, bool> next_state_rev;
            if (current_state.second) { 
                next_state_rev = {(current_state.first - 1 + n) % n, false};
            } else { 
                next_state_rev = {(current_state.first + 1) % n, true};
            }
            
            if (visited.find(next_state_rev) == visited.end()) {
                visited[next_state_rev] = ops + 1;
                q.push({next_state_rev, ops + 1});
            }
        }

        return -1; 
    }
};
