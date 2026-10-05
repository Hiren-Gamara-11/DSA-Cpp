// ============================================================
// LeetCode #977 - Squares of a Sorted Array
//
// Problem:
// Given a sorted array, return a new array containing the
// squares of each number, also sorted in non-decreasing order.
//
// Approach:
// Use two pointers at the beginning and end of the array.
// The largest square will come from either the leftmost
// negative number or the rightmost positive number.
// Compare both squares and place the larger one at the end
// of the result array.
//
// Tags: Array, Two Pointers, Sorting
//
// Time Complexity: O(n)
// Space Complexity: O(n)
// ============================================================

#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    vector<int> sortedSquares(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> result(n);

        int left = 0;
        int right = n - 1;

        for (int i = n - 1; i >= 0; i--)
        {
            int leftSquare = nums[left] * nums[left];
            int rightSquare = nums[right] * nums[right];

            if (leftSquare > rightSquare)
            {
                result[i] = leftSquare;
                left++;
            }
            else
            {
                result[i] = rightSquare;
                right--;
            }
        }

        return result;
    }
};