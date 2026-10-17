// Problem: Minimum Swaps to Sort by Digit Sum
// Difficulty: MEDIUM
// Link: https://leetcode.com/problems/minimum-swaps-to-sort-by-digit-sum/
// Approach: Augment numbers with their digit sums and original indices, then sort these pairs using the custom criteria. Calculate the minimum swaps to bring the original numbers to their sorted positions using cycle detection.

class Solution {
private:
    
    int calculate_digit_sum(int n) {
        int sum = 0;
        while (n > 0) {
            sum += n % 10;
            n /= 10;
        }
        return sum;
    }

public:
    int minSwaps(vector<int>& nums) {
        int n = nums.size();

        
        
        
        
        
        vector<pair<pair<int, int>, int>> arr_with_indices(n);
        for (int i = 0; i < n; ++i) {
            int ds = calculate_digit_sum(nums[i]);
            arr_with_indices[i] = {{ds, nums[i]}, i};
        }

        
        
        
        sort(arr_with_indices.begin(), arr_with_indices.end());

        
        vector<int> desired_pos(n);
        for (int i = 0; i < n; ++i) {
            
            
            desired_pos[arr_with_indices[i].second] = i;
        }

        
        
        
        
        int swaps = 0;
        vector<bool> visited(n, false); 

        for (int i = 0; i < n; ++i) {
            
            
            if (visited[i] || desired_pos[i] == i) {
                continue;
            }

            
            int cycle_size = 0;
            int current_node = i;
            while (!visited[current_node]) {
                visited[current_node] = true;
                current_node = desired_pos[current_node]; 
                cycle_size++;
            }
            
            swaps += (cycle_size - 1);
        }

        return swaps;
    }
};
