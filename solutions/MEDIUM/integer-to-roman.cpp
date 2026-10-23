// Problem: Integer to Roman
// Difficulty: MEDIUM
// Link: https://leetcode.com/problems/integer-to-roman/
// Approach: Use a greedy approach by iterating through a pre-defined list of Roman numeral values and their corresponding symbols (including subtractive forms like 900 for CM), ordered from largest to smallest. For each value, repeatedly append its symbol to the result and subtract its value from the input number until the number is smaller than the current value.

class Solution {
public:
    string intToRoman(int num) {
        vector<int> values = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
        vector<string> symbols = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};

        string result = "";

        for (int i = 0; i < values.size(); ++i) {
            while (num >= values[i]) {
                result += symbols[i];
                num -= values[i];
            }
        }

        return result;
    }
};
