/*
===========================================================
Problem    : Fibonacci Number
Platform   : LeetCode 509
Topic      : Recursion
Approach   : Recursive (Top-Down)
Time       : O(2^n)
Space      : O(n)

Description:
- Return the nth Fibonacci number.
- Fibonacci sequence:
  F(0) = 0
  F(1) = 1
  F(n) = F(n-1) + F(n-2)

Algorithm:
1. If n is 0 or 1, return n.
2. Recursively compute:
      fib(n-1) + fib(n-2)
3. Return the result.

Note:
- This is the brute-force recursive solution.
- It recalculates the same subproblems many times.
- Dynamic Programming (Memoization/Tabulation) is much more efficient.

===========================================================
*/

using namespace std;

class Solution {
public:
    int fib(int n) {

        // Base case
        if (n <= 1)
            return n;

        // Recursive relation
        return fib(n - 1) + fib(n - 2);
    }
};