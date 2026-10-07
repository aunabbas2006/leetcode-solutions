// Problem: Remove Invalid Parentheses
// Difficulty: HARD
// Link: https://leetcode.com/problems/remove-invalid-parentheses/
// Approach: Breadth-First Search (BFS) explores strings formed by iteratively removing one parenthesis at a time, level by level, until the first set of valid strings are found at the minimum removal depth.

class Solution {
public:
    
    
    bool isValid(const string& s) {
        int balance = 0;
        for (char c : s) {
            if (c == '(') {
                balance++;
            } else if (c == ')') {
                balance--;
            }
            if (balance < 0) {
                return false; 
            }
        }
        return balance == 0; 
    }

    vector<string> removeInvalidParentheses(string s) {
        
        set<string> result_set; 
        
        queue<string> q;
        
        set<string> visited; 

        q.push(s);
        visited.insert(s);

        
        
        bool found_valid_at_current_level = false; 

        while (!q.empty()) {
            
            int level_size = q.size(); 

            
            for (int i = 0; i < level_size; ++i) {
                string current = q.front();
                q.pop();

                if (isValid(current)) {
                    result_set.insert(current);
                    found_valid_at_current_level = true;
                }

                
                
                
                if (found_valid_at_current_level) {
                    continue; 
                }

                
                for (int j = 0; j < current.length(); ++j) {
                    if (current[j] == '(' || current[j] == ')') {
                        
                        string next_s = current.substr(0, j) + current.substr(j + 1);

                        
                        if (visited.find(next_s) == visited.end()) {
                            visited.insert(next_s);
                            q.push(next_s);
                        }
                    }
                }
            }

            
            
            
            if (found_valid_at_current_level) {
                break;
            }
        }
        
        
        vector<string> result_vec(result_set.begin(), result_set.end());
        return result_vec;
    }
};
