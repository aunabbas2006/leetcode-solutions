// Problem: First Missing Positive
// Difficulty: HARD
// Link: https://leetcode.com/problems/first-missing-positive/
// Approach: Utilize the array's indices as a hash map by cyclically swapping positive numbers `x` to their correct position `x-1`, then iterate through the modified array to find the first index `i` where `nums[i]` does not equal `i+1`.

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int N = nums.size();

        for (int i = 0; i < N; ++i) {
            while (nums[i] > 0 && nums[i] <= N && nums[i] != nums[nums[i]-1]) {
                int correctIndex = nums[i] - 1;
                int temp = nums[i];
                nums[i] = nums[correctIndex];
                nums[correctIndex] = temp;
            }
        }

        for (int i = 0; i < N; ++i) {
            if (nums[i] != i + 1) {
                return i + 1;
            }
        }

        return N + 1;
    }
};
