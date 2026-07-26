/*
====================================================
Problem: 303. Range Sum Query - Immutable
Platform: LeetCode
Difficulty: Easy
Topic: Array, Prefix Sum
Pattern: Prefix Sum
Time: O(n) preprocessing, O(1) per query
Space: O(n)
====================================================
*/

#include<vector>
using namespace std;

class NumArray {
private:
    vector<long long> prefixSum;

public:
    NumArray(vector<int>& nums) {
        long long sum = 0;

        for (int x : nums) {
            sum += x;
            prefixSum.push_back(sum);
        }
    }

    int sumRange(int left, int right) {
        if (left == 0)
            return prefixSum[right];

        return prefixSum[right] - prefixSum[left - 1];
    }
};

/*
====================================================
Revision Map:

                RANGE SUM QUERY
                       │
                       ▼
                PREFIX SUM
                       │
          ┌────────────┴────────────┐
          │                         │
     Preprocessing                Query
          │                         │
          ▼                         ▼
      O(n) Time                 O(1) Time
      O(n) Space
          │
          ▼
   prefix[i] = sum of
   nums[0] to nums[i]
          │
          ▼
   Example:
   nums = [-2, 0, 3, -5, 2, -1]

   prefix = [-2, -2, 1, -4, -2, -3]
          │
          ▼
      sumRange(left, right)
          │
      ┌───┴───────────────┐
      │                   │
    left = 0           left > 0
      │                   │
      ▼                   ▼
  prefix[right]   prefix[right]
                  - prefix[left-1]
                  
Preprocessing: O(n)
Each Query:    O(1)
Space:         O(n)
====================================================        
*/