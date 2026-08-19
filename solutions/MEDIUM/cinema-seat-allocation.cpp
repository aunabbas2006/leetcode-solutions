// Problem: Cinema Seat Allocation
// Difficulty: MEDIUM
// Link: https://leetcode.com/problems/cinema-seat-allocation/
// Approach: Group reserved seats by row using a hash map, representing seat reservations as a bitmask for efficient checking. For each row, prioritize two non-overlapping groups (2-5 and 6-9); if not possible, check for one group from any valid block (2-5, 4-7, or 6-9), summing these with two groups for all completely empty rows.

class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        map<int, int> row_occupied_mask; 

        for (const auto& seat_info : reservedSeats) {
            int row = seat_info[0];
            int seat = seat_info[1];

            
            if (seat >= 2 && seat <= 9) {
                
                
                row_occupied_mask[row] |= (1 << (seat - 2));
            }
        }

        int total_groups = 0;

        
        
        
        
        total_groups += (n - row_occupied_mask.size()) * 2;

        
        for (const auto& entry : row_occupied_mask) {
            int occupied_mask = entry.second;
            int current_row_groups = 0;

            
            
            
            

            bool left_block_available = (occupied_mask & 0b00001111) == 0;
            bool middle_block_available = (occupied_mask & 0b00111100) == 0;
            bool right_block_available = (occupied_mask & 0b11110000) == 0;

            
            
            
            if (left_block_available && right_block_available) {
                current_row_groups = 2;
            } 
            
            
            
            else if (left_block_available || middle_block_available || right_block_available) {
                current_row_groups = 1;
            }
            
            
            total_groups += current_row_groups;
        }

        return total_groups;
    }
};
