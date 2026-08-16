/*
=====================================================

LeetCode 2029 — Stone Game IX
Difficulty: Medium
Topic: Game Theory, Greedy, Math

Approach:
1. Count stones based on their remainder when divided by 3:
   - remainder 0 → zeros
   - remainder 1 → ones
   - remainder 2 → twos
2. Stones with remainder 0 do not change the current sum modulo 3,
   but they affect whose turn it is.
3. If zeros is even, Alice wins only when both remainder-1 and
   remainder-2 stones are available.
4. If zeros is odd, Alice wins when the difference between the
   counts of remainder-1 and remainder-2 stones is greater than 2.

Time Complexity: O(n)
Space Complexity: O(1)

=====================================================
*/

#include <vector>
using namespace std;

class Solution {
public:
    bool stoneGameIX(vector<int>& stones) {
        int zeros = 0;
        int ones = 0;
        int twos = 0;

        for (int i = 0; i < stones.size(); ++i) {
            int r = stones[i] % 3;

            if (r == 0)
                ++zeros;
            else if (r == 1)
                ++ones;
            else
                ++twos;
        }

        if (zeros % 2 == 0)
            return ones > 0 && twos > 0;
        else
            return abs(ones - twos) > 2;
    }
};