// Problem: Brace Expansion II
// Difficulty: HARD
// Link: https://leetcode.com/problems/brace-expansion-ii/
// Approach: Recursive descent parsing evaluates expressions by prioritizing concatenation (Cartesian product) over union (set union), accumulating unique words in a `TreeSet` for sorted output.

class Solution {
private:
    string expr;
    int current_pos;

    
    
    bool is_letter(char c) {
        return c >= 'a' && c <= 'z';
    }

    
    
    set<string> parseExpression() {
        set<string> result_union;
        
        
        set<string> first_term = parseTerm();
        result_union.insert(first_term.begin(), first_term.end());

        
        while (current_pos < expr.length() && expr[current_pos] == ',') {
            current_pos++; 
            set<string> next_term = parseTerm();
            result_union.insert(next_term.begin(), next_term.end()); 
        }
        return result_union;
    }

    
    
    set<string> parseTerm() {
        set<string> result_concat;
        result_concat.insert(""); 

        
        while (current_pos < expr.length()) {
            char c = expr[current_pos];
            
            if (is_letter(c) || c == '{') { 
                set<string> factor = parseBase(); 
                set<string> new_result_concat;
                
                for (const string& s1 : result_concat) {
                    for (const string& s2 : factor) {
                        new_result_concat.insert(s1 + s2);
                    }
                }
                result_concat = new_result_concat; 
            } else {
                
                break;
            }
        }
        return result_concat;
    }

    
    set<string> parseBase() {
        set<string> result_base;
        char c = expr[current_pos];

        if (is_letter(c)) {
            result_base.insert(string(1, c)); 
            current_pos++; 
        } else if (c == '{') {
            current_pos++; 
            result_base = parseExpression(); 
            current_pos++; 
        }
        return result_base;
    }

public:
    vector<string> braceExpansionII(string expression) {
        this->expr = expression;
        this->current_pos = 0;

        
        set<string> final_set = parseExpression();

        
        
        vector<string> final_list(final_set.begin(), final_set.end());
        
        return final_list;
    }
};
