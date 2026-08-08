/*
==================================================
LeetCode 561 - Array Partition
Difficulty: Easy
Topics: Array, Greedy, Sorting

Approach:
1. Sort the array in ascending order.
2. Pair adjacent elements.
3. Add the elements at even indices.
4. This maximizes the sum of the minimum values.

Time Complexity: O(n log n)
Space Complexity: O(1) auxiliary space
==================================================
*/

#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int arrayPairSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        int sum = 0;

        for (int i = 0; i < nums.size(); i += 2) {
            sum += nums[i];
        }

        return sum;
    }
};