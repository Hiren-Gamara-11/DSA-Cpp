// ============================================================
// LeetCode #125 - Valid Palindrome
//
// Problem:
// Determine whether a string is a palindrome after converting
// uppercase letters to lowercase and ignoring non-alphanumeric
// characters.
//
// Approach:
// Use two pointers, one at the beginning and one at the end.
// Skip non-alphanumeric characters, compare characters after
// converting them to lowercase, and move both pointers inward.
//
// Tags: Two Pointers, String
//
// Time Complexity: O(n)
// Space Complexity: O(1)
// ============================================================

#include <string>
#include <cctype>
using namespace std;

class Solution
{
public:
    bool isPalindrome(string s)
    {
        int left = 0;
        int right = s.size() - 1;

        while (left < right)
        {
            while (left < right && !isalnum(s[left]))
            {
                left++;
            }

            while (left < right && !isalnum(s[right]))
            {
                right--;
            }

            if (tolower(s[left]) != tolower(s[right]))
            {
                return false;
            }

            left++;
            right--;
        }

        return true;
    }
};