/*==================================================
2958. Length of Longest Subarray With at Most K Frequency

Difficulty : Medium
Topic      : Sliding Window, Hash Map

Approach:
1. Use two pointers: start and end.
2. Store frequency of each number in unordered_map.
3. Expand the window using end.
4. If any number appears k + 1 times, the window becomes invalid.
5. Move start forward until the invalid frequency is removed.
6. The answer is the maximum valid window length.

Time Complexity : O(n)
Space Complexity: O(n)
==================================================*/

#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int n = nums.size();

        unordered_map<int, int> frequency;

        int start = 0;
        int charsWithFreqOverK = 0;

        for (int end = 0; end < n; end++) {
            frequency[nums[end]]++;

            if (frequency[nums[end]] == k + 1) {
                charsWithFreqOverK++;
            }

            if (charsWithFreqOverK > 0) {
                frequency[nums[start]]--;

                if (frequency[nums[start]] == k) {
                    charsWithFreqOverK--;
                }

                start++;
            }
        }

        return n - start;
    }
};