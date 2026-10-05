// ============================================================
// LeetCode #344 - Reverse String
//
// Problem:
// Reverse the given string in-place.
//
// Approach:
// Use two pointers, one at the beginning and one at the end.
// Swap the characters at both pointers and move them toward
// the center until the entire string is reversed.
//
// Tags: Two Pointers, String
//
// Time Complexity: O(n)
// Space Complexity: O(1)
// ============================================================

#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class Solution
{
public:
    void reverseString(vector<char> &s)
    {
        int left = 0;
        int right = s.size() - 1;

        while (left < right)
        {
            swap(s[left], s[right]);
            left++;
            right--;
        }
    }
};