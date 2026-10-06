// ============================================================
// 75. Sort Colors
// LeetCode: https://leetcode.com/problems/sort-colors/
// Section: Arrays
//
// Approach:
// Use the Dutch National Flag algorithm with three pointers:
// low, mid, and high.
// - 0 → move to the left
// - 1 → keep in the middle
// - 2 → move to the right
//
// Time Complexity: O(n)
// Space Complexity: O(1)
// ============================================================

class Solution
{
public:
    void sortColors(vector<int> &nums)
    {
        int low = 0, mid = 0;
        int high = nums.size() - 1;

        while (mid <= high)
        {
            if (nums[mid] == 0)
            {
                swap(nums[low], nums[mid]);
                low++;
                mid++;
            }
            else if (nums[mid] == 1)
            {
                mid++;
            }
            else
            {
                swap(nums[mid], nums[high]);
                high--;
            }
        }
    }
};