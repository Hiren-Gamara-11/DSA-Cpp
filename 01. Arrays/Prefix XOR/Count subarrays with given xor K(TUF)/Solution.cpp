/*
==================================================
Count Subarrays With Given XOR K
==================================================

Approach:
Prefix XOR + Frequency Hashmap

Time Complexity: O(n) average
Space Complexity: O(n)
==================================================
*/

#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
public:
    int subarraysWithXorK(vector<int> &nums, int k) {
        unordered_map<int, int> mp;

        int prefixXor = 0;
        int count = 0;

        mp[0] = 1;

        for (int num : nums) {
            prefixXor ^= num;

            int required = prefixXor ^ k;

            count += mp[required];  // Existing key → frequency, missing key → 0

            mp[prefixXor]++;
        }

        return count;
    }
};