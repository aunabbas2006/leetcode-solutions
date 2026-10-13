// Problem: Maximum Alternating Sum of Squares
// Difficulty: MEDIUM
// Link: https://leetcode.com/problems/maximum-alternating-sum-of-squares/
// Approach: Calculate the square of each number, sort these squared values in descending order, then sum them with alternating signs (add the largest, subtract the next largest, add the third largest, and so on).

class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        int n = nums.size();
        
        vector<long long> squares;
        
        for (int x : nums) {
            squares.push_back((long long)x * x);
        }
        
        sort(squares.begin(), squares.end());
        
        long long total_score = 0;
        
        int num_positive_terms = (n + 1) / 2;
        int num_negative_terms = n / 2;
        
        for (int i = 0; i < num_positive_terms; ++i) {
            total_score += squares[n - 1 - i];
        }
        
        for (int i = 0; i < num_negative_terms; ++i) {
            total_score -= squares[i];
        }
        
        return total_score;
    }
};
