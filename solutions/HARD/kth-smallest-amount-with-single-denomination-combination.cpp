// Problem: Kth Smallest Amount With Single Denomination Combination
// Difficulty: HARD
// Link: https://leetcode.com/problems/kth-smallest-amount-with-single-denomination-combination/
// Approach: Binary search on the target amount, using the Principle of Inclusion-Exclusion to count how many unique multiples are less than or equal to a given value.

class Solution {
public:
    long long gcd(long long a, long long b) {
        while (b) {
            a %= b;
            long long temp = a;
            a = b;
            b = temp;
        }
        return a;
    }

    long long calculateLcm(long long a, long long b, long long limit) {
        if (a == 0 || b == 0) return 0; 
        if (a == 1) return b; 
        if (b == 1) return a; 

        if (a > limit) return limit + 1;

        long long common = gcd(a, b);
        long long res_factor = a / common;
        
        if (res_factor > limit / b) { 
            return limit + 1;
        }
        
        return res_factor * b;
    }

    long long count(long long target_amount, const vector<int>& coins) {
        long long total_count = 0;
        int n = coins.size();

        for (int i = 1; i < (1 << n); ++i) {
            long long current_lcm = 1;
            int set_bits = 0;          

            for (int j = 0; j < n; ++j) {
                if ((i >> j) & 1) { 
                    set_bits++;
                    current_lcm = calculateLcm(current_lcm, coins[j], target_amount);
                    
                    if (current_lcm > target_amount) {
                        break; 
                    }
                }
            }
            
            if (current_lcm > target_amount) { 
                 continue;
            }

            if (set_bits % 2 == 1) { 
                total_count += (target_amount / current_lcm);
            } else { 
                total_count -= (target_amount / current_lcm);
            }
        }
        return total_count;
    }

    long long findKthSmallest(vector<int>& coins, int k) {
        long long low = 1;
        long long high = 2000000000LL * 25 + 1; 
        long long ans = high; 

        while (low <= high) {
            long long mid = low + (high - low) / 2;
            if (count(mid, coins) >= k) {
                ans = mid;         
                high = mid - 1;
            } else {
                low = mid + 1;     
            }
        }
        return ans;
    }
};
