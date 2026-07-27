/*
============================================================
Problem: Majority Element II
Platform: LeetCode
Problem No.: 229
Topic: Array, Greedy, Boyer-Moore Voting Algorithm
Difficulty: Medium

Approach: Extended Boyer-Moore Voting Algorithm
Time Complexity: O(n)
Space Complexity: O(1)
============================================================
*/

#include <vector>
#include <climits>
using namespace std;

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();

        int cnt1 = 0, cnt2 = 0;
        int el1 = INT_MIN, el2 = INT_MIN;

        // Find potential candidates
        for (int i = 0; i < n; i++) {
            if (cnt1 == 0 && el2 != nums[i]) {
                cnt1 = 1;
                el1 = nums[i];
            }
            else if (cnt2 == 0 && el1 != nums[i]) {
                cnt2 = 1;
                el2 = nums[i];
            }
            else if (nums[i] == el1) {
                cnt1++;
            }
            else if (nums[i] == el2) {
                cnt2++;
            }
            else {
                cnt1--;
                cnt2--;
            }
        }

        // Validate candidates
        cnt1 = 0;
        cnt2 = 0;

        for (int i = 0; i < n; i++) {
            if (nums[i] == el1)
                cnt1++;

            if (nums[i] == el2)
                cnt2++;
        }

        int mini = n / 3 + 1;
        vector<int> result;

        if (cnt1 >= mini)
            result.push_back(el1);

        if (cnt2 >= mini && el1 != el2)
            result.push_back(el2);

        return result;
    }
};
