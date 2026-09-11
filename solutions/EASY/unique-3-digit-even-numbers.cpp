// Problem: Unique 3-Digit Even Numbers
// Difficulty: EASY
// Link: https://leetcode.com/problems/unique-3-digit-even-numbers/
// Approach: Iterate through all possible three-digit even numbers (from 100 to 998). For each candidate number, check if its constituent digits can be formed using the available counts of digits from the input array.

class Solution {
public:
    int totalNumbers(vector<int>& digits) {
        vector<int> digit_counts(10, 0);
        for (int digit : digits) {
            digit_counts[digit]++;
        }

        int count = 0;

        for (int num = 100; num <= 999; ++num) {
            if (num % 2 == 0) {
                int d1 = num / 100;
                int d2 = (num / 10) % 10;
                int d3 = num % 10;

                vector<int> temp_counts = digit_counts;

                temp_counts[d1]--;
                temp_counts[d2]--;
                temp_counts[d3]--;

                if (temp_counts[d1] >= 0 && 
                    temp_counts[d2] >= 0 && 
                    temp_counts[d3] >= 0) {
                    count++;
                }
            }
        }
        return count;
    }
};
