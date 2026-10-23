// Problem: Maximum K to Sort a Permutation
// Difficulty: MEDIUM
// Link: https://leetcode.com/problems/maximum-k-to-sort-a-permutation/
// Approach: Iterate `k` downwards from `n-1`. For each `k`, verify if every index `i` and its value `nums[i]` are either both bitwise-AND compatible with `k` or both incompatible; if incompatible, they must already be in their sorted positions. The first `k` that satisfies these conditions is the maximum.

class Solution {
public:
    vector<int> parent;
    vector<int> component_AND_val;

    int find(int i) {
        if (parent[i] == i)
            return i;
        return parent[i] = find(parent[i]);
    }

    void unite(int i, int j) {
        int root_i = find(i);
        int root_j = find(j);
        if (root_i != root_j) {
            parent[root_j] = root_i;
            component_AND_val[root_i] &= component_AND_val[root_j];
        }
    }

    int sortPermutation(vector<int>& nums) {
        int n = nums.size();

        bool isSorted = true;
        for (int i = 0; i < n; ++i) {
            if (nums[i] != i) {
                isSorted = false;
                break;
            }
        }
        if (isSorted) {
            return 0;
        }

        parent.resize(n);
        for (int i = 0; i < n; ++i) {
            parent[i] = i;
        }
        
        component_AND_val.resize(n);
        for (int i = 0; i < n; ++i) {
            component_AND_val[i] = i;
        }

        for (int i = 0; i < n; ++i) {
            if (nums[i] != i) {
                unite(i, nums[i]);
            }
        }

        int final_k_candidate = (1 << 20) - 1; 
        
        vector<bool> roots_processed(n, false); 
        for (int i = 0; i < n; ++i) {
            if (nums[i] != i) { 
                int root_of_component = find(i);
                if (!roots_processed[root_of_component]) {
                    final_k_candidate &= component_AND_val[root_of_component];
                    roots_processed[root_of_component] = true;
                }
            }
        }
        
        return final_k_candidate;
    }
};
