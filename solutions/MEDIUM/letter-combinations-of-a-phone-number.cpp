// Problem: Letter Combinations of a Phone Number
// Difficulty: MEDIUM
// Link: https://leetcode.com/problems/letter-combinations-of-a-phone-number/
// Approach: Use a recursive backtracking approach to build combinations. For each digit, iterate through its mapped letters, appending one to the current string and recursively calling for the next digit.

class Solution {
private:
    void backtrack(int index, string& currentCombination, const string& digits, 
                   const string mapping[], vector<string>& result) {
        if (index == digits.length()) {
            result.push_back(currentCombination);
            return;
        }

        char digitChar = digits[index];
        int digitVal = digitChar - '0';
        const string& letters = mapping[digitVal];

        for (char letter : letters) {
            currentCombination.push_back(letter);
            backtrack(index + 1, currentCombination, digits, mapping, result);
            currentCombination.pop_back();
        }
    }

public:
    vector<string> letterCombinations(string digits) {
        vector<string> result;

        if (digits.empty()) {
            return result;
        }

        string mapping[] = {
            "",     
            "",     
            "abc",  
            "def",  
            "ghi",  
            "jkl",  
            "mno",  
            "pqrs", 
            "tuv",  
            "wxyz"  
        };

        string currentCombination;
        backtrack(0, currentCombination, digits, mapping, result);

        return result;
    }
};
