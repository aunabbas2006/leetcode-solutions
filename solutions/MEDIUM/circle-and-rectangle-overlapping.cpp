// Problem: Circle and Rectangle Overlapping
// Difficulty: MEDIUM
// Link: https://leetcode.com/problems/circle-and-rectangle-overlapping/
// Approach: Find the point on the rectangle closest to the circle's center by clamping the circle's center coordinates to the rectangle's bounds, then check if the squared distance between the circle's center and this closest point is less than or equal to the squared radius.

class Solution {
public:
    bool checkOverlap(int radius, int xCenter, int yCenter, int x1, int y1, int x2, int y2) {
        int closestX;
        
        if (xCenter < x1) {
            closestX = x1;
        } else if (xCenter > x2) {
            closestX = x2;
        } else {
            closestX = xCenter; 
        }

        int closestY;
        
        if (yCenter < y1) {
            closestY = y1;
        } else if (yCenter > y2) {
            closestY = y2;
        } else {
            closestY = yCenter; 
        }

        
        
        long long dx = (long long)xCenter - closestX;
        long long dy = (long long)yCenter - closestY;
        long long distSq = dx * dx + dy * dy;

        
        long long radiusSq = (long long)radius * radius;

        
        
        return distSq <= radiusSq;
    }
};
