// Problem: Container With Most Water
// Difficulty: MEDIUM
// Link: https://leetcode.com/problems/container-with-most-water/
// Approach: Two-pointer approach, starting with pointers at both ends of the array, calculating the area, and moving the pointer associated with the shorter line inward to potentially form a larger container.

class Solution {
public:
    int maxArea(vector<int>& height) {
        int left = 0;
        int right = height.size() - 1;
        int max_water = 0;

        while (left < right) {
            int current_height = (height[left] < height[right]) ? height[left] : height[right];
            int width = right - left;
            
            max_water = (max_water > current_height * width) ? max_water : current_height * width;

            if (height[left] < height[right]) {
                left++;
            } else {
                right--;
            }
        }
        return max_water;
    }
};
