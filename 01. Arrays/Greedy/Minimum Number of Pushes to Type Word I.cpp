/*
===========================================================
 * Problem: Minimum Number of Pushes to Type Word I
 * LeetCode: 3016
 *
 * Approach:
 * Each key can hold at most 8 letters.
 * The first 8 letters require 1 push,
 * the next 8 require 2 pushes, and so on.
 *
 * Time Complexity: O(n)
 * Space Complexity: O(1)
===========================================================
 */

#include <string>
using namespace std; 

class Solution {
public:
    int minimumPushes(string word) {
        int n = word.size();
        int pushes = 0;

        for(int i = 0; i < n; i++) {
            pushes += (i / 8) + 1;
        }

        return pushes;
    }
};
