// Problem: Construct Uniform Parity Array II
// Difficulty: MEDIUM
// Link: https://leetcode.com/problems/construct-uniform-parity-array-ii/
// Approach: Determine the counts of odd and even numbers in the input array and find its minimum element. The target array can be made uniformly even if all original numbers are even, or uniformly odd if all original numbers are odd or if the minimum number in the input array is odd.

class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        int countOdd = 0;
        int minVal = 1000000001; 

        for (int x : nums1) {
            if (x % 2 != 0) {
                countOdd++;
            }
            if (x < minVal) {
                minVal = x;
            }
        }

        int n = nums1.size();
        int countEven = n - countOdd;

        
        
        
        if (countOdd == 0) {
            return true;
        }

        
        
        
        
        
        
        
        
        
        
        
        
        if (countEven == 0 || minVal % 2 != 0) {
            return true;
        }

        
        return false;
    }
};
