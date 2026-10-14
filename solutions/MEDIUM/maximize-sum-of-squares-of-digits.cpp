// Problem: Maximize Sum of Squares of Digits
// Difficulty: MEDIUM
// Link: https://leetcode.com/problems/maximize-sum-of-squares-of-digits/
// Approach: A greedy approach constructs the number digit by digit from left to right, choosing the largest possible digit at each position that allows the remaining digits to form the required sum, thereby maximizing both the sum of squares and the resulting number.

class Solution {
public:
    string maxSumOfSquares(int num, int sum) {
        
        
        

        
        
        
        
        
        if (sum > num * 9) {
            return "";
        }

        
        
        
        
        
        

        string result(num, ' '); 
        int current_sum_needed = sum;

        for (int i = 0; i < num; ++i) {
            int lower_digit_bound;
            if (i == 0) {
                
                lower_digit_bound = 1;
            } else {
                
                lower_digit_bound = 0;
            }

            
            
            
            
            
            
            int remaining_digits_count = num - 1 - i;
            int min_digit_needed_for_remaining_sum = current_sum_needed - remaining_digits_count * 9;

            
            
            
            int actual_lower_bound = max(lower_digit_bound, min_digit_needed_for_remaining_sum);

            
            
            
            int actual_upper_bound = min(9, current_sum_needed);

            
            
            
            if (actual_lower_bound > actual_upper_bound) {
                return ""; 
            }

            
            
            int chosen_digit = actual_upper_bound;
            
            result[i] = chosen_digit + '0'; 
            current_sum_needed -= chosen_digit; 
        }

        
        
        return result;
    }
};
