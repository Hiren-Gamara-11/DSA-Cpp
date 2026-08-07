/*
===========================================
3348. Smallest Divisible Digit Product II
===========================================

Topic:
- Greedy
- Number Theory
- Math
- String

Difficulty:
- Hard

Approach:
1. Check whether t can be represented using digits (2-9).
2. Compute rem[i]:
   rem[i] = remaining factor of t after using the first i digits.
3. If the original number already satisfies the condition,
   return it.
4. Traverse from right to left and try increasing one digit.
5. Greedily fill the remaining suffix with the largest possible
   digits from the right to obtain the smallest overall number.
6. If no answer of the same length exists, construct the smallest
   valid number with length n + 1.

Time Complexity : O(n)
Space Complexity: O(n)

===========================================
*/

#include <string>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

class Solution {
public:
    string smallestNumber(string num, long long t) {

        // Check whether t can be represented using digits 2-9.
        long long temp = t;
        for (int i = 2; i <= 9; i++) {
            while (temp % i == 0) {
                temp /= i;
            }
        }

        if (temp > 1) {
            return "-1";
        }

        int n = num.length();

        // rem[i] = remaining factor after processing first i digits.
        vector<long long> rem(n + 1);
        rem[0] = t;

        int pos = n - 1;

        for (int i = 0; i < n; i++) {

            // Zero cannot appear in the answer.
            if (num[i] == '0') {
                pos = i;
                break;
            }

            rem[i + 1] = rem[i] / gcd(rem[i], (long long)(num[i] - '0'));
        }

        // Original number already works.
        if (rem[n] == 1) {
            return num;
        }

        // Try increasing digits from right to left.
        for (int i = pos; i >= 0; i--) {

            while (++num[i] <= '9') {

                long long remaining =
                    rem[i] / gcd(rem[i], (long long)(num[i] - '0'));

                int digit = 9;

                // Build the smallest suffix.
                for (int j = n - 1; j > i; j--) {

                    while (remaining % digit != 0) {
                        digit--;
                    }

                    remaining /= digit;
                    num[j] = char('0' + digit);
                }

                if (remaining == 1) {
                    return num;
                }
            }
        }

        // Same length is impossible.
        // Build the smallest answer with one extra digit.
        string ans;

        for (int digit = 9; digit >= 2; digit--) {
            while (t % digit == 0) {
                ans += char('0' + digit);
                t /= digit;
            }
        }

        ans += string(max(n + 1 - (int)ans.length(), 0), '1');

        reverse(ans.begin(), ans.end());

        return ans;
    }
};