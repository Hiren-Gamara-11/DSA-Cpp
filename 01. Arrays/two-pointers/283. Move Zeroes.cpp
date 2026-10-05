// ============================================================
// LeetCode #283 - Move Zeroes
//
// Problem:
// Move all zeroes to the end of the array while maintaining
// the relative order of the non-zero elements.
//
// Approach:
// Use two pointers. The first pointer keeps track of the
// position where the next non-zero element should be placed.
// Traverse the array and swap each non-zero element with the
// element at the current position.
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
    void moveZeroes(vector<int> &nums)
    {
        int j = 0;

        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] != 0)
            {
                swap(nums[i], nums[j]);
                j++;
            }
        }
    }
};