// Problem: Maximum Number of Non-Overlapping Substrings
// Difficulty: HARD
// Link: https://leetcode.com/problems/maximum-number-of-non-overlapping-substrings/
// Approach: Iterate through the string, for each potential start position, expand to find the smallest valid substring that contains all occurrences of its characters. Then, greedily select non-overlapping substrings by sorting them by end position, then by length, picking the first available one.

class Solution {
public:
    vector<string> maxNumOfSubstrings(string s) {
        int n = s.length();

        vector<int> first(26, n); 
        vector<int> last(26, -1); 

        for (int i = 0; i < n; ++i) {
            int char_idx = s[i] - 'a';
            first[char_idx] = min(first[char_idx], i); 
            last[char_idx] = max(last[char_idx], i);  
        }

        vector<pair<int, int>> candidates; 

        for (int i = 0; i < n; ++i) {
            
            
            
            if (i != first[s[i] - 'a']) {
                continue;
            }

            int current_L = i;
            int current_R = last[s[i] - 'a']; 
            bool possible_candidate = true;

            
            
            
            int k = current_L;
            while (k <= current_R) {
                int k_char_idx = s[k] - 'a';
                
                
                
                
                
                if (first[k_char_idx] < current_L) {
                    possible_candidate = false;
                    break; 
                }
                
                
                
                current_R = max(current_R, last[k_char_idx]);
                k++;
            }

            
            if (possible_candidate) {
                candidates.push_back({current_L, current_R});
            }
        }
        
        
        
        
        sort(candidates.begin(), candidates.end(), [](const pair<int, int>& a, const pair<int, int>& b) {
            if (a.second != b.second) {
                return a.second < b.second; 
            }
            
            return (a.second - a.first) < (b.second - b.first); 
        });

        vector<string> result;
        int prev_end = -1; 

        
        for (const auto& p : candidates) {
            
            
            
            if (p.first > prev_end) { 
                result.push_back(s.substr(p.first, p.second - p.first + 1));
                prev_end = p.second; 
            }
        }

        return result;
    }
};
