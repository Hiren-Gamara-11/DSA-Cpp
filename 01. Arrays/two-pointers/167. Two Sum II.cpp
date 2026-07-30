/* 
==================================================
Problem: 167. Two Sum II - Input Array Is Sorted
Platform: LeetCode
Difficulty: Medium
Topic: Array, Two Pointers 
Pattern: Two Pointers 
==================================================

Approach 1: Brute Force
- Check every possible pair using two nested loops.
- Does not utilize the sorted property of the array.
Time: O(n^2)
Space: O(1)

--------------------------------------------------

Approach 2: Optimal
- Use two pointers, one starting at the beginning and one at the end of the array
- Move the pointers based on the sum of the two numbers compared to the target
Time: O(n)
Space: O(1)
Pattern: Two Pointers

==================================================
*/

#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int left = 0;
        int right = numbers.size() - 1;

        while(left<right){
            int sum = numbers[left] + numbers[right];

            if(sum < target)
                left++;
            else if(sum > target)
                right--;
            else
                return {left+1,right+1};
        }
        return {};
    }
};