// Problem: Sum Game
// Difficulty: MEDIUM
// Link: https://leetcode.com/problems/sum-game/
// Approach: Calculate the initial difference between the sums of digits in the first and second halves, and the difference in the count of question marks between the two halves. Based on these differences, determine the final sum difference assuming optimal play: if the question mark count difference is positive, Alice adds to the sum; if negative, Bob reduces the sum. Bob wins if this final sum difference is zero, otherwise Alice wins.

class Solution {
public:
    bool sumGame(string num) {
        long long sumL = 0;
        long long sumR = 0;
        int qL = 0;
        int qR = 0;
        int n = num.length();

        for (int i = 0; i < n / 2; ++i) {
            if (num[i] == '?') {
                qL++;
            } else {
                sumL += num[i] - '0';
            }
        }

        for (int i = n / 2; i < n; ++i) {
            if (num[i] == '?') {
                qR++;
            } else {
                sumR += num[i] - '0';
            }
        }

        long long diff = sumL - sumR;
        int q_diff = qL - qR;

        
        
        
        if (q_diff % 2 != 0) {
            return true; 
        }
        
        
        
        
        
        if (diff + (q_diff / 2) * 9 == 0) {
            return false; 
        } else {
            return true; 
        }
    }
};
