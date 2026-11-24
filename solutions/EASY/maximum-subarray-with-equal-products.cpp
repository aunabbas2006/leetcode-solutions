// Problem: Maximum Subarray With Equal Products
// Difficulty: EASY
// Link: https://leetcode.com/problems/maximum-subarray-with-equal-products/
// Approach: Iterate over all possible subarrays. For each subarray, collect the prime factor exponents for each relevant prime (2, 3, 5, 7) from its elements. A subarray is product equivalent if, for every prime, all these collected exponents except possibly the minimum and maximum are zero. Track the maximum length found.

class Solution {
private:
    static vector<map<int, int>> prime_factors_cache;
    static bool precomputed;
    
    static void precompute_factors_once() {
        if (precomputed) {
            return;
        }
        
        prime_factors_cache.resize(11); 
        for (int i = 1; i <= 10; ++i) {
            int temp = i;
            for (int p = 2; p * p <= temp; ++p) {
                if (temp % p == 0) {
                    int count = 0;
                    while (temp % p == 0) {
                        count++;
                        temp /= p;
                    }
                    prime_factors_cache[i][p] = count;
                }
            }
            if (temp > 1) { 
                prime_factors_cache[i][temp] = 1;
            }
        }
        precomputed = true;
    }

public:
    int maxLength(vector<int>& nums) {
        precompute_factors_once();
        
        int n = nums.size();
        int max_len = 0;
        
        vector<int> all_primes = {2, 3, 5, 7};
        
        for (int i = 0; i < n; ++i) {
            vector<vector<int>> current_exponents_for_primes(all_primes.size());
            
            for (int j = i; j < n; ++j) {
                int num = nums[j];
                
                for (int p_idx = 0; p_idx < all_primes.size(); ++p_idx) {
                    int p = all_primes[p_idx];
                    current_exponents_for_primes[p_idx].push_back(
                        prime_factors_cache[num].count(p) ? prime_factors_cache[num][p] : 0
                    );
                }
                
                bool is_product_equivalent = true;
                for (int p_idx = 0; p_idx < all_primes.size(); ++p_idx) {
                    int min_e = current_exponents_for_primes[p_idx][0];
                    int max_e = current_exponents_for_primes[p_idx][0];
                    long long sum_e = 0;
                    
                    for (int exp : current_exponents_for_primes[p_idx]) {
                        sum_e += exp;
                        min_e = min(min_e, exp);
                        max_e = max(max_e, exp);
                    }
                    
                    if (sum_e != (long long)min_e + max_e) {
                        is_product_equivalent = false;
                        break;
                    }
                }
                
                if (is_product_equivalent) {
                    max_len = max(max_len, j - i + 1);
                }
            }
        }
        
        return max_len;
    }
};

vector<map<int, int>> Solution::prime_factors_cache;
bool Solution::precomputed = false;
