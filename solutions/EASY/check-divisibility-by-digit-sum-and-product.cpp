// Problem: Check Divisibility by Digit Sum and Product
// Difficulty: EASY
// Link: https://leetcode.com/problems/check-divisibility-by-digit-sum-and-product/
// Approach: Iteratively extract digits from `n` using modulo and division to compute both the digit sum and digit product, then check if `n` is divisible by the sum of these two calculated values.

class Solution {
public:
    bool checkDivisibility(int n) {
        int temp_n = n;
        int digit_sum = 0;
        int digit_product = 1;

        while (temp_n > 0) {
            int digit = temp_n % 10;
            digit_sum += digit;
            digit_product *= digit;
            temp_n /= 10;
        }

        int combined_sum = digit_sum + digit_product;
        
        return n % combined_sum == 0;
    }
};
