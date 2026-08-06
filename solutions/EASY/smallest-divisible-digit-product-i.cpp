// Problem: Smallest Divisible Digit Product I
// Difficulty: EASY
// Link: https://leetcode.com/problems/smallest-divisible-digit-product-i/
// Approach: Iteratively check numbers starting from `n`, calculate the product of their digits, and return the first number found whose digit product is divisible by `t`.

class Solution {
private:
    int getDigitProduct(int num) {
        int product = 1;
        int temp = num;
        while (temp > 0) {
            int digit = temp % 10;
            if (digit == 0) {
                return 0;
            }
            product *= digit;
            temp /= 10;
        }
        return product;
    }

public:
    int smallestNumber(int n, int t) {
        for (int x = n; ; ++x) {
            int product = getDigitProduct(x);
            if (product % t == 0) {
                return x;
            }
        }
        return -1; 
    }
};
