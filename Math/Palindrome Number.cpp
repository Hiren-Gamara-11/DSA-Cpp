/*
    Problem: Palindrome Number
    Category: Math / Numbers

    Approach: Mathematical Digit Reversal
    - Negative numbers cannot be palindromes.
    - Store the original number for comparison.
    - Extract each digit using x % 10.
    - Build the reversed number using:
      reversed = reversed * 10 + digit
    - Remove the last digit using x / 10.
    - Compare the original number with the reversed number.
    - If both are equal, the number is a palindrome.

    Time Complexity: O(log10(n))
    Space Complexity: O(1)
*/

#include <cstdint>

class Solution {
public:
    bool isPalindrome(int x) {
        // Negative numbers are not palindrome
        if (x < 0) {
            return false;
        }

        int original = x;
        long long reversed = 0;

        while (x != 0) {
            int digit = x % 10;
            reversed = reversed * 10 + digit;
            x = x / 10;
        }

        return original == reversed;
    }
};