// Problem: Sum of Sortable Integers
// Difficulty: HARD
// Link: https://leetcode.com/problems/sum-of-sortable-integers/
// Approach: First, sort the input array to obtain the target `sorted_nums`. Then, for each divisor `k` of `n`, verify if every `k`-length subarray of `nums` is an anagram of its corresponding `k`-length subarray in `sorted_nums` using frequency counts, summing `k` if all blocks satisfy this condition.

class Solution {
public:
    int sortableIntegers(vector<int>& nums) {
        int n = nums.size();

        vector<int> sorted_nums = nums;
        sort(sorted_nums.begin(), sorted_nums.end());

        map<int, long long> val_to_hash;
        mt19937_64 eng(chrono::steady_clock::now().time_since_epoch().count());
        uniform_int_distribution<long long> dist;

        for (int x : nums) {
            if (val_to_hash.find(x) == val_to_hash.end()) {
                val_to_hash[x] = dist(eng);
            }
        }

        vector<long long> prefix_xor_orig(n + 1, 0);
        vector<long long> prefix_xor_sorted(n + 1, 0);

        for (int i = 0; i < n; ++i) {
            prefix_xor_orig[i+1] = prefix_xor_orig[i] ^ val_to_hash[nums[i]];
            prefix_xor_sorted[i+1] = prefix_xor_sorted[i] ^ val_to_hash[sorted_nums[i]];
        }

        int total_sum = 0;
        vector<int> divisors;
        for (int i = 1; i * i <= n; ++i) {
            if (n % i == 0) {
                divisors.push_back(i);
                if (i * i != n) {
                    divisors.push_back(n / i);
                }
            }
        }

        long long P1 = 100003;
        long long MOD1 = 1000000007;
        long long P2 = 100007;
        long long MOD2 = 1000000009;

        vector<long long> powP1(n + 1);
        vector<long long> powP2(n + 1);
        powP1[0] = 1;
        powP2[0] = 1;
        for (int i = 1; i <= n; ++i) {
            powP1[i] = (powP1[i-1] * P1) % MOD1;
            powP2[i] = (powP2[i-1] * P2) % MOD2;
        }

        for (int k : divisors) {
            bool is_k_sortable = true;

            
            for (int block_idx = 0; block_idx < n / k; ++block_idx) {
                int L = block_idx * k;
                int R = (block_idx + 1) * k - 1;

                long long xor_hash_orig = prefix_xor_orig[R+1] ^ prefix_xor_orig[L];
                long long xor_hash_sorted = prefix_xor_sorted[R+1] ^ prefix_xor_sorted[L];

                if (xor_hash_orig != xor_hash_sorted) {
                    is_k_sortable = false;
                    break;
                }
            }

            if (!is_k_sortable) {
                continue;
            }

            
            for (int block_idx = 0; block_idx < n / k; ++block_idx) {
                int L = block_idx * k;
                int R = (block_idx + 1) * k - 1;

                vector<int> current_block_A_elements(nums.begin() + L, nums.begin() + R + 1);
                vector<int> current_block_B_elements(sorted_nums.begin() + L, sorted_nums.begin() + R + 1);

                long long hash_B1 = 0;
                long long hash_B2 = 0;
                for (int val : current_block_B_elements) {
                    hash_B1 = (hash_B1 * P1 + val) % MOD1;
                    hash_B2 = (hash_B2 * P2 + val) % MOD2;
                }

                long long current_hash_A1 = 0;
                long long current_hash_A2 = 0;
                for (int val : current_block_A_elements) {
                    current_hash_A1 = (current_hash_A1 * P1 + val) % MOD1;
                    current_hash_A2 = (current_hash_A2 * P2 + val) % MOD2;
                }

                bool found_cyclic_shift_for_block = false;
                for (int j = 0; j < k; ++j) { 
                    if (current_hash_A1 == hash_B1 && current_hash_A2 == hash_B2) {
                        found_cyclic_shift_for_block = true;
                        break;
                    }
                    
                    
                    
                    current_hash_A1 = (current_hash_A1 - (long long)current_block_A_elements[j] * powP1[k-1] % MOD1 + MOD1) % MOD1;
                    current_hash_A1 = (current_hash_A1 * P1 % MOD1 + current_block_A_elements[j]) % MOD1;

                    current_hash_A2 = (current_hash_A2 - (long long)current_block_A_elements[j] * powP2[k-1] % MOD2 + MOD2) % MOD2;
                    current_hash_A2 = (current_hash_A2 * P2 % MOD2 + current_block_A_elements[j]) % MOD2;
                }
                
                if (!found_cyclic_shift_for_block) {
                    is_k_sortable = false;
                    break;
                }
            }

            if (is_k_sortable) {
                total_sum += k;
            }
        }

        return total_sum;
    }
};
