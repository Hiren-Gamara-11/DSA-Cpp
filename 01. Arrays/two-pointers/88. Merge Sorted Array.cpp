/*
========================================
LeetCode 88. Merge Sorted Array
========================================

Approach:
- Use three pointers starting from the end.
- Compare the largest remaining elements in nums1 and nums2.
- Place the larger one at the end of nums1.
- Copy any remaining elements from nums2.

Time Complexity : O(m + n)
Space Complexity: O(1)

Topics:
Array | Two Pointers

Algorithms:
Two Pointers
In-place Array Manipulation
Reverse Traversal

========================================
*/

#include <vector>
using namespace std;

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i = m - 1;
        int j = n - 1;
        int k = m + n - 1;

        while (i >= 0 && j >= 0) {
            if (nums1[i] > nums2[j]) {
                nums1[k--] = nums1[i--];
            } else {
                nums1[k--] = nums2[j--];
            }
        }                  
                         
        while (j >= 0) {
            nums1[k--] = nums2[j--];
        }
    }
};