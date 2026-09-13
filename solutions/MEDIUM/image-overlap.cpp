// Problem: Image Overlap
// Difficulty: MEDIUM
// Link: https://leetcode.com/problems/image-overlap/
// Approach: Iterate through all possible relative horizontal and vertical shifts of one image compared to the other, calculate the overlap for each shift by counting matching '1's in corresponding cells, and return the maximum.

class Solution {
public:
    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
        int n = img1.size();
        int maxOverlap = 0;

        for (int dy = -(n - 1); dy < n; ++dy) {
            for (int dx = -(n - 1); dx < n; ++dx) {
                int currentOverlap = 0;

                for (int r = 0; r < n; ++r) {
                    for (int c = 0; c < n; ++c) {
                        if (img2[r][c] == 1) {
                            int pr = r - dy; 
                            int pc = c - dx; 

                            if (pr >= 0 && pr < n && pc >= 0 && pc < n && img1[pr][pc] == 1) {
                                currentOverlap++;
                            }
                        }
                    }
                }
                maxOverlap = (currentOverlap > maxOverlap) ? currentOverlap : maxOverlap;
            }
        }

        return maxOverlap;
    }
};
