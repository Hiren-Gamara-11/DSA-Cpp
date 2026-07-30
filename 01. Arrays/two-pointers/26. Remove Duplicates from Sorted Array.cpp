/*
==================================================
Problem: Remove Duplicates from Sorted Array
LeetCode: 26

Approach:
Use two pointers to keep only unique elements
in the sorted array.

Time Complexity: O(n)
Space Complexity: O(1)
==================================================
*/

#include <vector>
using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int k = 1;
        for (int i = 1; i < nums.size(); i++) {   
            if (nums[i] != nums[i - 1]) {
                nums[k] = nums[i];
                k++;
            }
        }
        return k;
    }
};