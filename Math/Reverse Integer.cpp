/*
    Problem: Reverse Integer
    Category: Math / Numbers

    Approach: Mathematical Digit Extraction
    - Extract the last digit using x % 10.
    - Add the extracted digit to the reversed number.
    - Remove the last digit from x using x / 10.
    - Check for integer overflow/underflow before multiplying the
      reversed number by 10.
    - Return 0 if the reversed integer exceeds the 32-bit range.

    Time Complexity: O(log10(n))
    Space Complexity: O(1)
*/

#include <climits>

class Solution {
public:
    int reverse(int x) {
        int reminder;
        int reversed = 0;

        while (x != 0) {
            reminder = x % 10;

            // Check for integer overflow
            if (reversed > INT_MAX / 10 ||
                (reversed == INT_MAX / 10 && reminder > 7))
                return 0;

            // Check for integer underflow
            if (reversed < INT_MIN / 10 ||
                (reversed == INT_MIN / 10 && reminder < -8))
                return 0;

            reversed = reversed * 10 + reminder;

            x /= 10;
        }

        return reversed;
    }
};