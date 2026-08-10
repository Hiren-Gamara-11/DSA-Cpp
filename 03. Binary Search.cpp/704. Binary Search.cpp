/*
==================================================
704. Binary Search
Difficulty: Easy
Topic: Binary Search

Approach:
1. Set left = 0 and right = n - 1.
2. Find the middle element.
3. If nums[mid] == target, return mid.
4. If nums[mid] < target, search right half.
5. Otherwise, search left half.
6. If target is not found, return -1.

Time Complexity: O(log n)
Space Complexity: O(1)
==================================================
*/

#include <vector>
using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;

        while (left <= right) {
            int mid = left + (right - left) / 2;

            if (nums[mid] == target)
                return mid;

            if (nums[mid] < target)
                left = mid + 1;
            else
                right = mid - 1;
        }

        return -1;
    }
};