/*
===========================================================
Problem    : Frequency of the Most Frequent Element
Platform   : LeetCode 1838
Topic      : Arrays
Pattern    : Sliding Window + Sorting
Approach   : Sort + Variable Size Sliding Window
Time       : O(n log n)
Space      : O(1)   // Ignoring sorting space

Description:
- Given an integer array and an integer k.
- In one operation, increase any element by 1.
- Return the maximum possible frequency of an element after at most k operations.

Algorithm:
1. Sort the array.
2. Maintain a sliding window [left...right].
3. Keep the sum of elements inside the window.
4. Calculate the operations required to make every element equal to nums[right]:
      required = nums[right] * windowSize - sum
5. If required > k, shrink the window from the left.
6. Update the maximum window size.

Key Idea:
- After sorting, only increase smaller elements to match the largest
  element in the current window.

===========================================================
*/

#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {

        // Sort the array
        sort(nums.begin(), nums.end());

        long long sum = 0;   // Sum of current window
        int left = 0;
        int ans = 1;

        for (int right = 0; right < nums.size(); right++) {

            // Add current element to window sum
            sum += nums[right];

            // Shrink window if operations exceed k
            while ((long long)nums[right] * (right - left + 1) - sum > k) {
                sum -= nums[left];
                left++;
            }

            // Update maximum frequency
            ans = max(ans, right - left + 1);
        }

        return ans;
    }
};