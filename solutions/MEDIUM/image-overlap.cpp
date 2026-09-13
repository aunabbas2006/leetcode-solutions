// Problem: Image Overlap
// Difficulty: MEDIUM
// Link: https://leetcode.com/problems/image-overlap/
// Approach: Iterate through all possible horizontal and vertical shifts for one image relative to the other. For each translation, count the number of positions where both images have a '1' in their overlapping region, and return the maximum count.

class Solution {
public:
    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
        int n = img1.size();
        
        vector<pair<int, int>> ones1;
        vector<pair<int, int>> ones2;
        
        for (int r = 0; r < n; ++r) {
            for (int c = 0; c < n; ++c) {
                if (img1[r][c] == 1) {
                    ones1.push_back({r, c});
                }
                if (img2[r][c] == 1) {
                    ones2.push_back({r, c});
                }
            }
        }
        
        map<pair<int, int>, int> translationCounts;
        int maxOverlap = 0;
        
        
        
        
        
        
        
        
        
        for (auto const& p1 : ones1) { 
            for (auto const& p2 : ones2) { 
                int dy = p1.first - p2.first;
                int dx = p1.second - p2.second;
                translationCounts[{dy, dx}]++;
            }
        }
        
        
        
        
        for (auto const& entry : translationCounts) {
            if (entry.second > maxOverlap) {
                maxOverlap = entry.second;
            }
        }
        
        return maxOverlap;
    }
};
