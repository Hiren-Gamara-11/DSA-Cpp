/*
===========================================================
Problem    : Valid Palindrome
Platform   : LeetCode 125
Approach   : Two Pointers
Time       : O(n)
Space      : O(1)

Description:
- Ignore all non-alphanumeric characters.
- Compare remaining characters in a case-insensitive manner.
- Return true if the string is a palindrome, otherwise false.

Algorithm:
1. Initialize two pointers:
   - start = 0
   - end = s.size() - 1
2. Skip non-alphanumeric characters from both ends.
3. Compare lowercase versions of the characters.
4. If they differ, return false.
5. Move both pointers inward and continue.
6. If all comparisons match, return true.

Key Functions:
- isalnum() : Checks whether a character is a letter or digit.
- tolower() : Converts an uppercase letter to lowercase.

===========================================================
*/

#include <string>     // string
#include <cctype>     // isalnum(), tolower()

using namespace std;

class Solution {
public:
    bool isPalindrome(string s) {
        int start = 0;
        int end = s.size() - 1;

        while (start <= end) {

            // Skip non-alphanumeric character from left
            if (!isalnum(s[start])) {
                start++;
                continue;
            }

            // Skip non-alphanumeric character from right
            if (!isalnum(s[end])) {
                end--;
                continue;
            }

            // Compare characters (case-insensitive)
            if (tolower(s[start]) != tolower(s[end]))
                return false;

            start++;
            end--;
        }

        return true;
    }
};