// Problem: Smallest Unique Subarray
// Difficulty: HARD
// Link: https://leetcode.com/problems/smallest-unique-subarray/
// Approach: Construct a suffix automaton to count occurrences of all substrings in linear time. Iterate through the automaton's states to identify the minimum length `L` for which any represented substring appears exactly once.

class Solution {
private:
    
    
    static const long long P1 = 100003; 
    static const long long M1 = 1000000007; 

    
    static const long long P2 = 100007; 
    static const long long M2 = 1000000009; 

    
    bool check(int k, int N, const vector<int>& nums, const vector<long long>& P_powers1, const vector<long long>& P_powers2) {
        if (k == 0) return false;

        
        
        
        map<pair<long long, long long>, int> counts;

        long long current_hash1 = 0;
        long long current_hash2 = 0;

        
        for (int i = 0; i < k; ++i) {
            current_hash1 = (current_hash1 * P1 + nums[i]) % M1;
            current_hash2 = (current_hash2 * P2 + nums[i]) % M2;
        }
        counts[{current_hash1, current_hash2}]++;

        
        long long P_pow_k_minus_1_1 = P_powers1[k - 1];
        long long P_pow_k_minus_1_2 = P_powers2[k - 1];

        
        for (int i = 1; i <= N - k; ++i) {
            
            current_hash1 = (current_hash1 - (long long)nums[i-1] * P_pow_k_minus_1_1 % M1 + M1) % M1;
            current_hash1 = (current_hash1 * P1 + nums[i+k-1]) % M1;
            
            
            current_hash2 = (current_hash2 - (long long)nums[i-1] * P_pow_k_minus_1_2 % M2 + M2) % M2;
            current_hash2 = (current_hash2 * P2 + nums[i+k-1]) % M2;

            counts[{current_hash1, current_hash2}]++;
        }

        
        for (auto const& entry : counts) {
            if (entry.second == 1) {
                return true;
            }
        }
        return false;
    }

public:
    int smallestUniqueSubarray(vector<int>& nums) {
        int N = nums.size();
        
        
        
        vector<long long> P_powers1(N + 1);
        vector<long long> P_powers2(N + 1);
        P_powers1[0] = 1;
        P_powers2[0] = 1;
        for (int i = 1; i <= N; ++i) {
            P_powers1[i] = (P_powers1[i-1] * P1) % M1;
            P_powers2[i] = (P_powers2[i-1] * P2) % M2;
        }

        
        
        int low = 1, high = N;
        int ans = N; 

        while (low <= high) {
            int mid = low + (high - low) / 2; 
            
            
            
            if (check(mid, N, nums, P_powers1, P_powers2)) {
                ans = mid;
                high = mid - 1;
            } else {
                
                
                low = mid + 1;
            }
        }
        
        return ans;
    }
};
