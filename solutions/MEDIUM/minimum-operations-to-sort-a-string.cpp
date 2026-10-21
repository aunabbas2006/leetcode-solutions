// Problem: Minimum Operations to Sort a String
// Difficulty: MEDIUM
// Link: https://leetcode.com/problems/minimum-operations-to-sort-a-string/
// Approach: Compare the string `s` with its sorted version `s_target` to find the minimal unsorted contiguous segment `s[L...R]`. If `s` is sorted, return 0; if `s` has length 2 and is unsorted, return -1; if `s[L...R]` is not the entire string, return 1. Otherwise (the whole string needs sorting), simulate one operation by sorting a non-entire substring (e.g., `s[0...N-2]`); if the resulting string `s'` can then be sorted with one operation on a non-entire substring, return 2, otherwise return 3.

class Solution {
public:
    int minOperations(string s) {
        int n = s.length();

        string s_sorted = s;
        sort(s_sorted.begin(), s_sorted.end());

        if (s == s_sorted) {
            return 0;
        }

        int first_diff = 0;
        while (first_diff < n && s[first_diff] == s_sorted[first_diff]) {
            first_diff++;
        }

        int last_diff = n - 1;
        while (last_diff >= 0 && s[last_diff] == s_sorted[last_diff]) {
            last_diff--;
        }

        
        
        
        if (first_diff > 0 || last_diff < n - 1) {
            return 1;
        }

        
        
        
        

        if (n == 2) {
            
            
            
            return -1;
        }

        
        
        
        

        
        string s_temp1 = s;
        sort(s_temp1.begin(), s_temp1.begin() + n - 1);

        
        
        int fd1 = 0;
        while (fd1 < n && s_temp1[fd1] == s_sorted[fd1]) {
            fd1++;
        }
        int ld1 = n - 1;
        while (ld1 >= 0 && s_temp1[ld1] == s_sorted[ld1]) {
            ld1--;
        }
        if (fd1 > 0 || ld1 < n - 1) {
            return 2; 
        }

        
        string s_temp2 = s;
        sort(s_temp2.begin() + 1, s_temp2.end());

        
        int fd2 = 0;
        while (fd2 < n && s_temp2[fd2] == s_sorted[fd2]) {
            fd2++;
        }
        int ld2 = n - 1;
        while (ld2 >= 0 && s_temp2[ld2] == s_sorted[ld2]) {
            ld2--;
        }
        if (fd2 > 0 || ld2 < n - 1) {
            return 2; 
        }

        
        
        return 3;
    }
};
