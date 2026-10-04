/*
============================================================
LeetCode 1480 - Running Sum of 1d Array
Category: Array
Difficulty: Easy

Approach:
Traverse the array and maintain a running sum.
Store the current sum at each index.
============================================================
*/

#include <vector>
using namespace std;

class Solution
{
public:
    vector<int> runningSum(vector<int> &nums)
    {
        for (int i = 1; i < nums.size(); i++)
        {
            nums[i] += nums[i - 1];
        }
        return nums;

        /* Alternative approach using a temporary array
        vector<int> temp(nums.size());
        int count = 0;
        for(int i=0; i<nums.size(); i++){
            count += nums[i];
            temp[i] = count;
        }
        return temp;
        */
    }
};