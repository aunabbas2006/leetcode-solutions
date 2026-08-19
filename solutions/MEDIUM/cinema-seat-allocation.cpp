// Problem: Cinema Seat Allocation
// Difficulty: MEDIUM
// Link: https://leetcode.com/problems/cinema-seat-allocation/
// Approach: Group reserved seats by row using a hash map. For each row, determine the maximum groups (0, 1, or 2, prioritizing disjoint blocks) it can accommodate based on seat availability. Unreserved rows each contribute two groups.

class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        map<int, int> rowReservations; 

        
        for (const auto& seat : reservedSeats) {
            int r = seat[0];
            int s = seat[1];
            
            if (s >= 2 && s <= 9) {
                
                
                rowReservations[r] |= (1 << (s - 2));
            }
        }

        int totalGroups = 0;

        
        
        for (const auto& entry : rowReservations) {
            int mask = entry.second;
            int groupsInThisRow = 0;

            
            
            
            

            bool isLeftAvailable = (mask & 15) == 0;
            bool isMiddleAvailable = (mask & 60) == 0;
            bool isRightAvailable = (mask & 240) == 0;

            
            if (isLeftAvailable && isRightAvailable) {
                groupsInThisRow = 2;
            } 
            
            else if (isLeftAvailable || isMiddleAvailable || isRightAvailable) {
                groupsInThisRow = 1;
            }
            

            totalGroups += groupsInThisRow;
        }

        
        
        
        totalGroups += (n - rowReservations.size()) * 2;

        return totalGroups;
    }
};
