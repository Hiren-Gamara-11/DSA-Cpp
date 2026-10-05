// ============================================================
// LeetCode #189 - Rotate Array
//
// Problem:
// Rotate the array to the right by k steps.
//
// Approach:
// Use the reversal technique:
// 1. Reverse the entire array.
// 2. Reverse the first k elements.
// 3. Reverse the remaining elements.
//
// This rotates the array to the right by k positions while
// using constant extra space.
//
// Time Complexity: O(n)
// Space Complexity: O(1)
// ============================================================

#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    void rotate(vector<int> &nums, int k)
    {
        int n = nums.size();
        k = k % n;

        reverse(nums.begin(), nums.end());
        reverse(nums.begin(), nums.begin() + k);
        reverse(nums.begin() + k, nums.end());
    }
};