// Problem: Circle and Rectangle Overlapping
// Difficulty: MEDIUM
// Link: https://leetcode.com/problems/circle-and-rectangle-overlapping/
// Approach: Calculate the closest point on the rectangle to the circle's center, then determine if the squared distance from the circle's center to this closest point is less than or equal to the squared radius.

class Solution {
public:
    bool checkOverlap(int radius, int xCenter, int yCenter, int x1, int y1, int x2, int y2) {
        int closestX = max(x1, min(xCenter, x2));
        int closestY = max(y1, min(yCenter, y2));

        long long dx = xCenter - closestX;
        long long dy = yCenter - closestY;
        long long distanceSq = dx * dx + dy * dy;

        long long radiusSq = (long long)radius * radius;

        return distanceSq <= radiusSq;
    }
};
