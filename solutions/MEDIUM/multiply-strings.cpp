// Problem: Multiply Strings
// Difficulty: MEDIUM
// Link: https://leetcode.com/problems/multiply-strings/
// Approach: Simulate long multiplication by hand, iterating through digits from right to left, storing intermediate products and carries in a result array, then converting the array of digits to a string.

class Solution {
public:
    string multiply(string num1, string num2) {
        if (num1 == "0" || num2 == "0") {
            return "0";
        }

        vector<int> res(num1.length() + num2.length(), 0);

        
        for (int i = num1.length() - 1; i >= 0; i--) {
            int d1 = num1[i] - '0';
            
            for (int j = num2.length() - 1; j >= 0; j--) {
                int d2 = num2[j] - '0';

                
                int product = d1 * d2;

                
                
                
                int p1 = i + j + 1;
                int p2 = i + j;

                
                int sum = res[p1] + product;

                res[p1] = sum % 10;
                res[p2] += sum / 10; 
            }
        }

        
        string result_str = "";
        int i = 0;
        
        
        while (i < res.size() && res[i] == 0) {
            i++;
        }
        
        
        
        
        if (i == res.size()) {
            return "0";
        }

        
        while (i < res.size()) {
            result_str += (char)(res[i] + '0');
            i++;
        }

        return result_str;
    }
};
