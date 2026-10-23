// Problem: String to Integer (atoi)
// Difficulty: MEDIUM
// Link: https://leetcode.com/problems/string-to-integer-atoi/
// Approach: Iterate through the string, first skipping leading whitespace, then determining the sign. Subsequently, read digits one by one, accumulating the integer value while checking for and handling 32-bit integer overflow at each multiplication and addition step. Finally, clamp the result to the `[-2^31, 2^31 - 1]` range.

class Solution {
public:
    int myAtoi(string s) {
        int i = 0;
        int n = s.length();

        
        while (i < n && s[i] == ' ') {
            i++;
        }

        
        int sign = 1;
        if (i < n && s[i] == '-') {
            sign = -1;
            i++;
        } else if (i < n && s[i] == '+') {
            i++;
        }

        
        long long result = 0; 

        
        
        
        
        const int MAX_INT = 2147483647;
        const int MIN_INT = -2147483648;

        while (i < n && s[i] >= '0' && s[i] <= '9') {
            int digit = s[i] - '0';

            
            
            if (sign == 1) {
                if (result > MAX_INT / 10 || (result == MAX_INT / 10 && digit > MAX_INT % 10)) {
                    return MAX_INT;
                }
            } 
            
            else { 
                
                
                
                
                
                
                if (result > (long long)MAX_INT / 10 || (result == (long long)MAX_INT / 10 && digit > 8)) {
                    return MIN_INT;
                }
            }
            
            result = result * 10 + digit;
            i++;
        }

        
        return (int)(sign * result);
    }
};
