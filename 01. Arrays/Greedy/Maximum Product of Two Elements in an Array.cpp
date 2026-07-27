/*
============================================================

 Problem: Maximum Product of Two Elements in an Array
 Platform: LeetCode
 Problem No.: 1464
 Topic: Array, Greedy, One Pass
 Difficulty: Easy

 Approach: Find the two largest elements in one traversal
 Time Complexity: O(n)
 Space Complexity: O(1)

============================================================
*/

#include<vector>
using namespace std;

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int num1 = 0;
        int num2 = 0;

        for (int x : nums) {
            if (x > num1) {
                num2 = num1;
                num1 = x;
            } 
            else if (x > num2) {
                num2 = x;
            }
        }

        return (num1 - 1) * (num2 - 1);
    }
};