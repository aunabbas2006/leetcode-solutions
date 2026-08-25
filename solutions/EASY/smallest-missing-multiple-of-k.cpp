// Problem: Smallest Missing Multiple of K
// Difficulty: EASY
// Link: https://leetcode.com/problems/smallest-missing-multiple-of-k/
// Approach: Store the elements of `nums` in a hash set for efficient lookups, then iterate through positive multiples of `k` (k, 2k, 3k, ...) and return the first multiple not found in the hash set.

class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        
        
        
        
        
        
        
        
        
        bool present[201] = {false}; 

        
        
        
        for (int num : nums) {
            present[num] = true;
        }

        
        for (int current_multiple = k; ; current_multiple += k) {
            
            
            
            
            
            
            
            
            
            if (current_multiple > 200 || !present[current_multiple]) {
                return current_multiple;
            }
        }
    }
};
