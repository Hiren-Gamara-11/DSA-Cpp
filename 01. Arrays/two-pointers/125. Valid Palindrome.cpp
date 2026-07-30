/*
==================================================
Problem: 125. Valid Palindrome
Platform: LeetCode
Difficulty: Easy
Topic: String, Two Pointers
Pattern: Two Pointers

Approach: Two Pointers
- Use one pointer from the beginning and one from the end.
- Skip non-alphanumeric characters.
- Compare characters after converting them to lowercase.
- Move both pointers toward the center.

Time: O(n)
Space: O(1)
==================================================
*/

#include <string>
#include <cctype>
using namespace std;

class Solution {
public:
    bool isPalindrome(string s) {
        int start = 0;
        int end = s.size() - 1;

        while (start < end) {
            // Skip non-alphanumeric characters
            if (!isalnum(s[start])) {
                start++;
                continue;
            }
            if (!isalnum(s[end])) {
                end--;
                continue;
            }

            // Compare characters in a case-insensitive manner
            if (tolower(s[start]) != tolower(s[end])) 
                return false;

            start++;
            end--;
        }
        return true;
    }
};