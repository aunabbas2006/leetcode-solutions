// Problem: Count Commas in Range II
// Difficulty: MEDIUM
// Link: https://leetcode.com/problems/count-commas-in-range-ii/
// Approach: Iterate through thresholds `10^3, 10^6, 10^9, ...`, and for each threshold `T` less than or equal to `n`, add `n - T + 1` to the total comma count.

class Solution {
public:
    long long countCommas(long long n) {
        long long totalCommas = 0;

        long long threshold_1_start = 1000LL;
        if (n >= threshold_1_start) {
            totalCommas += (n - (threshold_1_start - 1));
        }

        long long threshold_2_start = 1000000LL;
        if (n >= threshold_2_start) {
            totalCommas += (n - (threshold_2_start - 1));
        }

        long long threshold_3_start = 1000000000LL;
        if (n >= threshold_3_start) {
            totalCommas += (n - (threshold_3_start - 1));
        }

        long long threshold_4_start = 1000000000000LL;
        if (n >= threshold_4_start) {
            totalCommas += (n - (threshold_4_start - 1));
        }

        long long threshold_5_start = 1000000000000000LL;
        if (n >= threshold_5_start) {
            totalCommas += (n - (threshold_5_start - 1));
        }
        
        return totalCommas;
    }
};
