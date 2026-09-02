// Problem: Construct Uniform Parity Array I
// Difficulty: EASY
// Link: https://leetcode.com/problems/construct-uniform-parity-array-i/
// Approach: Determine if `nums1` contains any odd numbers; if not, an all-even array is possible, otherwise an all-odd array is possible by strategically using an existing odd number to change the parity of even numbers.

class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        int n = nums1.size();
        if (n == 0) {
            
            
            return true;
        }

        int numOdd = 0;
        for (int x : nums1) {
            if (x % 2 != 0) { 
                numOdd++;
            }
        }

        
        

        
        
        
        
        
        
        
        
        
        
        
        
        bool possibleAllEven = (numOdd == 0 || numOdd >= 2);

        
        
        
        
        
        
        
        
        
        
        
        bool possibleAllOdd = (numOdd >= 1);

        
        
        return possibleAllEven || possibleAllOdd;
    }
};
