// Problem: Find the Lexicographically Smallest Valid Sequence
// Difficulty: MEDIUM
// Link: https://leetcode.com/problems/find-the-lexicographically-smallest-valid-sequence/
// Approach: Precompute next and previous character occurrences in `word1` for each character. Then, use these precomputed tables to iteratively build the lexicographically smallest sequence: for each position in the target sequence, try to match `word2`'s character or use a mismatch (if available) at the smallest possible index in `word1` that still allows for a valid completion of the remaining suffix.

class Solution {
public:
    vector<int> next_char_pos_global[26];
    vector<int> prev_char_pos_global[26];
    vector<int> next_mismatch_pos_global[26];
    vector<vector<int>> last_possible_start_idx;
    
    string word1_global;
    string word2_global;
    int n1_global;
    int n2_global;

    bool find(int k, int prev_idx, int diffs_allowed, vector<int>& current_ans) {
        if (k == n2_global) {
            return true;
        }

        int min_curr_idx_lower_bound = prev_idx + 1;
        
        
        
        
        
        int max_curr_idx_upper_bound = n1_global - (n2_global - k);

        if (min_curr_idx_lower_bound > max_curr_idx_upper_bound) {
            return false; 
        }

        int target_char_code = word2_global[k] - 'a';

        
        
        int idx_for_match = next_char_pos_global[target_char_code][min_curr_idx_lower_bound];
        bool can_take_match_option = false;
        if (idx_for_match <= max_curr_idx_upper_bound && 
            idx_for_match < last_possible_start_idx[k+1][diffs_allowed]) {
            can_take_match_option = true;
        }

        
        
        int idx_for_mismatch = n1_global; 
        bool can_take_mismatch_option = false;
        if (diffs_allowed > 0) {
            idx_for_mismatch = next_mismatch_pos_global[target_char_code][min_curr_idx_lower_bound];
            if (idx_for_mismatch <= max_curr_idx_upper_bound && 
                idx_for_mismatch < last_possible_start_idx[k+1][diffs_allowed - 1]) {
                can_take_mismatch_option = true;
            }
        }

        
        if (can_take_match_option && can_take_mismatch_option) {
            if (idx_for_match < idx_for_mismatch) {
                
                current_ans.push_back(idx_for_match);
                if (find(k + 1, idx_for_match, diffs_allowed, current_ans)) {
                    return true;
                }
                current_ans.pop_back();
                
                
                current_ans.push_back(idx_for_mismatch);
                if (find(k + 1, idx_for_mismatch, diffs_allowed - 1, current_ans)) {
                    return true;
                }
                current_ans.pop_back();
            } else { 
                
                current_ans.push_back(idx_for_mismatch);
                if (find(k + 1, idx_for_mismatch, diffs_allowed - 1, current_ans)) {
                    return true;
                }
                current_ans.pop_back();
                
                
                current_ans.push_back(idx_for_match);
                if (find(k + 1, idx_for_match, diffs_allowed, current_ans)) {
                    return true;
                }
                current_ans.pop_back();
            }
        } else if (can_take_match_option) {
            
            current_ans.push_back(idx_for_match);
            if (find(k + 1, idx_for_match, diffs_allowed, current_ans)) {
                return true;
            }
            current_ans.pop_back();
        } else if (can_take_mismatch_option) {
            
            current_ans.push_back(idx_for_mismatch);
            if (find(k + 1, idx_for_mismatch, diffs_allowed - 1, current_ans)) {
                return true;
            }
            current_ans.pop_back();
        }
        
        return false; 
    }

    vector<int> validSequence(string word1, string word2) {
        word1_global = word1;
        word2_global = word2;
        n1_global = word1.length();
        n2_global = word2.length();

        
        for (int c = 0; c < 26; ++c) {
            next_char_pos_global[c].assign(n1_global + 1, n1_global); 
            for (int i = n1_global - 1; i >= 0; --i) {
                next_char_pos_global[c][i] = next_char_pos_global[c][i + 1];
                if (word1_global[i] == ('a' + c)) {
                    next_char_pos_global[c][i] = i;
                }
            }
        }

        
        for (int c = 0; c < 26; ++c) {
            prev_char_pos_global[c].assign(n1_global, -1); 
            for (int i = 0; i < n1_global; ++i) {
                if (i > 0) {
                    prev_char_pos_global[c][i] = prev_char_pos_global[c][i-1];
                }
                if (word1_global[i] == ('a' + c)) {
                    prev_char_pos_global[c][i] = i;
                }
            }
        }

        
        for (int c = 0; c < 26; ++c) {
            next_mismatch_pos_global[c].assign(n1_global + 1, n1_global); 
            for (int i = n1_global - 1; i >= 0; --i) {
                next_mismatch_pos_global[c][i] = next_mismatch_pos_global[c][i + 1];
                if (word1_global[i] != ('a' + c)) {
                    next_mismatch_pos_global[c][i] = i;
                }
            }
        }

        
        
        
        last_possible_start_idx.assign(n2_global + 1, vector<int>(2, -2)); 
        
        
        
        
        
        last_possible_start_idx[n2_global][0] = n1_global; 
        last_possible_start_idx[n2_global][1] = n1_global;

        for (int k = n2_global - 1; k >= 0; --k) {
            for (int d = 0; d <= 1; ++d) {
                
                if (last_possible_start_idx[k+1][d] != -2) { 
                    
                    
                    
                    int upper_bound_for_current_idx = last_possible_start_idx[k+1][d] - 1;
                    if (upper_bound_for_current_idx >= 0) {
                        
                        int match_idx = prev_char_pos_global[word2_global[k]-'a'][upper_bound_for_current_idx];
                        if (match_idx != -1) {
                            last_possible_start_idx[k][d] = max(last_possible_start_idx[k][d], match_idx);
                        }
                    }
                }

                
                if (d > 0 && last_possible_start_idx[k+1][d-1] != -2) { 
                    
                    
                    int upper_bound_for_current_idx = last_possible_start_idx[k+1][d-1] - 1;
                    if (upper_bound_for_current_idx >= 0) {
                        
                        
                        
                        last_possible_start_idx[k][d] = max(last_possible_start_idx[k][d], upper_bound_for_current_idx);
                    }
                }
            }
        }

        vector<int> result_sequence;
        
        if (find(0, -1, 1, result_sequence)) {
            return result_sequence;
        } else {
            return {}; 
        }
    }
};
