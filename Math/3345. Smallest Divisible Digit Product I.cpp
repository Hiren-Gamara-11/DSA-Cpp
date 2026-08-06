/*
========================================
Problem: 3345. Smallest Divisible Digit Product I

Approach:
- Brute Force
- Simulation

Time Complexity: O(k * d)
    k = numbers checked
    d = number of digits

Space Complexity: O(d)
    (for string conversion)

Key Idea:
- Convert each number to a string.
- Compute the product of its digits.
- Return the first number whose digit product is divisible by t.
========================================
*/

#include <string>
using namespace std;

class Solution {
public:
    int smallestNumber(int n, int t) {
        while (true) {
            long long mul = 1;

            for (char c : to_string(n))
                mul *= (c - '0');

            if (mul % t == 0)
                return n;

            n++;
        }
    }
};