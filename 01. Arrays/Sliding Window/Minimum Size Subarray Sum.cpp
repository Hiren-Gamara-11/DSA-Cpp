/*
============================================================

 Problem: Minimum Size Subarray Sum
 Platform: LeetCode
 Problem No.: 209
 Topic: Array, Sliding Window, Two Pointers
 Difficulty: Medium

 Approach: Sliding Window
 Time Complexity: O(n)
 Space Complexity: O(1)

============================================================
*/

#include <vector>
#include <climits>
#include <algorithm>

using namespace std;

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int left = 0;
        int sum = 0;
        int ans = INT_MAX;

        for (int right = 0; right < nums.size(); right++) {
            sum += nums[right];

            while (sum >= target) {
                ans = min(ans, right - left + 1);
                sum -= nums[left];
                left++;
            }
        }

        return (ans == INT_MAX) ? 0 : ans;
    }
};