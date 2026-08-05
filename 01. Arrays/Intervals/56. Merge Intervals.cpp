/*
========================================
LeetCode 56. Merge Intervals
========================================

Approach:
- Sort intervals by starting point.
- Traverse intervals one by one.
- If current interval doesn't overlap with the last merged interval,
  push it into the answer.
- Otherwise, merge by extending the ending point.

Time Complexity : O(n log n)
Space Complexity: O(n) (including output)

Topics:
Array | Sorting | Intervals | Greedy

Algorithms:
Sorting
Greedy
Interval Merging
*/

#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> merged;

        for (auto interval : intervals) {
            if (merged.empty() || merged.back()[1] < interval[0]) {
                merged.push_back(interval);
            } else {
                merged.back()[1] = max(merged.back()[1],interval[1]);
            }
        }

        return merged;
    }
};