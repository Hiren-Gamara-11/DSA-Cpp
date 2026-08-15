/*===========================================================
Problem: 3702. Longest Subsequence With Non-Zero Bitwise XOR
Difficulty: Medium
Topic: Bit Manipulation, Greedy
Approach:
- Calculate the XOR of all elements.
- If the XOR is already non-zero, the entire array is valid.
- If the XOR is zero, remove one element that has a non-zero
  value to make the XOR non-zero.
- If all elements are zero, no valid subsequence exists.

Time Complexity: O(n)
Space Complexity: O(1)
===========================================================*/

#include <vector>
using namespace std;

class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int n = nums.size();
        int xorValue = 0;
        bool hasNonZero = false;

        for (int num : nums) {
            xorValue ^= num;
            if (num != 0) {
                hasNonZero = true;
            }
        }

        if (!hasNonZero) {
            return 0;
        }

        if (xorValue != 0) {
            return n;
        }

        return n - 1;
    }
};