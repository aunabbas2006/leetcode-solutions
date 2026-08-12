// Problem: Length of Longest Subarray With at Most K Frequency
// Difficulty: MEDIUM
// Link: https://leetcode.com/problems/length-of-longest-subarray-with-at-most-k-frequency/
// Approach: Sliding window using a hash map to track element frequencies, expanding the window and shrinking it from the left whenever any element's frequency exceeds `k`.

class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        unordered_map<int, int> freqMap;
        int left = 0;
        int maxLength = 0;
        
        for (int right = 0; right < nums.size(); ++right) {
            freqMap[nums[right]]++;
            
            while (freqMap[nums[right]] > k) {
                freqMap[nums[left]]--;
                left++;
            }
            
            maxLength = max(maxLength, right - left + 1);
        }
        
        return maxLength;
    }
};
