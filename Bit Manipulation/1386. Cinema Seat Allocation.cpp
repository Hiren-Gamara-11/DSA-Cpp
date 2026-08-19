/*
====================================================
LeetCode 1386 - Cinema Seat Allocation
Difficulty: Medium
Topic: Hashing, Bitmask, Greedy

Approach:
1. Store reserved seats of each affected row using a bitmask.
2. For every affected row, check the three possible
   groups of four seats:
      - 2,3,4,5
      - 4,5,6,7
      - 6,7,8,9
3. If both outer groups are available, we can place
   two families.
4. Otherwise, if at least one valid group is available,
   place one family.
5. Rows without reservations can always accommodate
   two families.

Time Complexity: O(R)
Space Complexity: O(R)
where R = number of reserved seats.
====================================================
*/

#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        unordered_map<int, int> rows;

        // Store reserved seats as a bitmask.
        for (const auto& seat : reservedSeats) {
            int row = seat[0];
            int col = seat[1];

            // Use bit (col - 1) for the seat.
            rows[row] |= (1 << (col - 1));
        }

        int answer = (n - rows.size()) * 2;

        // Masks for:
        // 2-5, 4-7, 6-9
        int left = 0b0000011110;
        int middle = 0b0001111000;
        int right = 0b0111100000;

        for (const auto& [row, mask] : rows) {
            bool canLeft = (mask & left) == 0;
            bool canMiddle = (mask & middle) == 0;
            bool canRight = (mask & right) == 0;

            if (canLeft && canRight) {
                answer += 2;
            }
            else if (canLeft || canMiddle || canRight) {
                answer += 1;
            }
        }

        return answer;
    }
};