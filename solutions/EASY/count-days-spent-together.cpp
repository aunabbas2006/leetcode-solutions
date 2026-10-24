// Problem: Count Days Spent Together
// Difficulty: EASY
// Link: https://leetcode.com/problems/count-days-spent-together/
// Approach: Convert all "MM-DD" dates to a numerical day-of-year representation, then calculate the length of the intersection of these two date ranges.

class Solution {
private:
    int dateToDayNumber(const string& dateStr) {
        int month = (dateStr[0] - '0') * 10 + (dateStr[1] - '0');
        int day = (dateStr[3] - '0') * 10 + (dateStr[4] - '0');

        vector<int> daysInMonth = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

        int dayNumber = 0;
        for (int i = 0; i < month - 1; ++i) {
            dayNumber += daysInMonth[i];
        }
        dayNumber += day;
        return dayNumber;
    }

public:
    int countDaysTogether(string arriveAlice, string leaveAlice, string arriveBob, string leaveBob) {
        int aliceArriveDay = dateToDayNumber(arriveAlice);
        int aliceLeaveDay = dateToDayNumber(leaveAlice);
        int bobArriveDay = dateToDayNumber(arriveBob);
        int bobLeaveDay = dateToDayNumber(leaveBob);

        int overlapStart = max(aliceArriveDay, bobArriveDay);
        int overlapEnd = min(aliceLeaveDay, bobLeaveDay);

        if (overlapStart <= overlapEnd) {
            return overlapEnd - overlapStart + 1;
        } else {
            return 0;
        }
    }
};
