/*
====================================================
Problem: 152. Maximum Product Subarray
Platform: LeetCode
Difficulty: Medium
Topic: Array, Dynamic Programming
Pattern: Kadane's Algorithm Variation

====================================================

Approach 1: Brute Force
- Generate every possible subarray.
- Calculate the product of each subarray.
- Keep track of the maximum product.

Time: O(n^2)
Space: O(1)

----------------------------------------------------

Approach 2: Optimal
- Track the maximum and minimum product ending at
  the current index.
- The minimum is necessary because multiplying a
  negative number by a negative product can produce
  the maximum positive product.
- If the current number is negative, swap currMax
  and currMin.

Time: O(n)
Space: O(1)

Pattern: Dynamic Programming / Kadane's Algorithm
         Variation

====================================================
*/

#include<vector>
using namespace std;

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int currMax = nums[0];
        int currMin = nums[0];
        int ans = nums[0];

        for (int i = 1; i < nums.size(); i++) {
            int x = nums[i];

            if (x < 0) {
                swap(currMax, currMin);
            }

            currMax = max(x, currMax * x);
            currMin = min(x, currMin * x);

            ans = max(ans, currMax);
        }

        return ans;
    }
};