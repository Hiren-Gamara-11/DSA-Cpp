/*
===========================================
540. Single Element in a Sorted Array (TUF -> BS on 1D)
===========================================

Approach:
- Binary Search
- Pair Index Pattern

Algorithm:
1. Compute mid.
2. If mid is odd, decrement it to make it even.
3. Compare nums[mid] with nums[mid + 1].
4. If they are equal, the single element lies on the right.
5. Otherwise, it lies on the left (including mid).
6. Continue until low == high.

Key Observation:
Before the single element:
    Pair starts at EVEN indices.
    [1,1] [2,2] [3,3]

After the single element:
    Pair starts at ODD indices.
    1 [2,2] [3,3]

Time Complexity: O(log n)
Space Complexity: O(1)

===========================================
*/

#include <vector>
using namespace std;

class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int low = 0;
        int high = nums.size() - 1;

        while (low < high) {
            int mid = low + (high - low) / 2;

            if (mid % 2 == 1)
                mid--;

            if (nums[mid] == nums[mid + 1])
                low = mid + 2;
            else
                high = mid;
        }

        return nums[low];
    }
};