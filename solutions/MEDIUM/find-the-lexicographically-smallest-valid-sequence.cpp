// Problem: Find the Lexicographically Smallest Valid Sequence
// Difficulty: MEDIUM
// Link: https://leetcode.com/problems/find-the-lexicographically-smallest-valid-sequence/
// Approach: A greedy selection of indices `i_j` from `word1` is performed for each character `word2[j]`. To ensure lexicographical minimality and validity, precompute `next_occurrence` tables and use dynamic programming to determine the minimum `word1` starting index from which a suffix of `word2` can be formed with allowed mismatches, then greedily choose the smallest valid `i_j` at each step.

vector<vector<int>> next_occurrence; 
string W1, W2;
int N_len, M_len;
vector<int> current_ans;

class Solution {
public:
    
    bool solve_dfs(int k, int prev_idx, int diff_count) {
        
        if (k == M_len) {
            return true;
        }

        
        
        
        
        
        
        int max_allowed_idx_for_current_step = N_len - M_len + k;

        
        int next_match_idx = N_len; 
        
        next_match_idx = next_occurrence[prev_idx + 1][W2[k] - 'a'];
        
        
        
        int next_mismatch_idx = N_len; 
        if (diff_count == 0) {
            
            for (int char_code = 0; char_code < 26; ++char_code) {
                if (char_code == (W2[k] - 'a')) { 
                    continue;
                }
                int idx = next_occurrence[prev_idx + 1][char_code];
                if (idx < N_len) { 
                    next_mismatch_idx = min(next_mismatch_idx, idx);
                }
            }
        }

        vector<pair<int, int>> candidates; 

        
        if (next_match_idx < N_len && next_match_idx <= max_allowed_idx_for_current_step) {
            candidates.push_back({next_match_idx, diff_count});
        }
        
        if (next_mismatch_idx < N_len && next_mismatch_idx <= max_allowed_idx_for_current_step) {
            candidates.push_back({next_mismatch_idx, 1}); 
        }

        
        
        
        sort(candidates.begin(), candidates.end()); 

        
        for (const auto& candidate : candidates) {
            int next_idx = candidate.first;
            int new_diff_count = candidate.second;

            current_ans.push_back(next_idx); 
            if (solve_dfs(k + 1, next_idx, new_diff_count)) {
                return true; 
            }
            current_ans.pop_back(); 
        }

        return false; 
    }

public:
    vector<int> validSequence(string word1, string word2) {
        W1 = word1;
        W2 = word2;
        N_len = W1.length();
        M_len = W2.length();

        
        
        
        next_occurrence.assign(N_len + 1, vector<int>(26, N_len));

        
        for (int i = N_len - 1; i >= 0; --i) {
            
            for (int char_code = 0; char_code < 26; ++char_code) {
                next_occurrence[i][char_code] = next_occurrence[i+1][char_code];
            }
            
            next_occurrence[i][W1[i] - 'a'] = i;
        }

        current_ans.clear(); 
        
        if (solve_dfs(0, -1, 0)) {
            return current_ans; 
        } else {
            return {}; 
        }
    }
};
