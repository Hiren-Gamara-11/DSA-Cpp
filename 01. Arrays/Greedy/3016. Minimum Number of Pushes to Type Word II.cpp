/*
==================================================
Minimum Number of Pushes to Type Word II
LeetCode 3016
==================================================

Approach:
1. Count the frequency of each character.
2. Sort frequencies in descending order.
3. Assign the most frequent characters to keys
   requiring the fewest pushes.
4. Every 8 characters increase the push count.

Time Complexity: O(n + 26 log 26)
Space Complexity: O(26)
==================================================
*/

#include <algorithm>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    int minimumPushes(string word) {
        vector<int> freq(26, 0); // Frequency array for 26 lowercase letters

        for (char c : word) {
            freq[c - 'a']++; // Count frequency of each character
        }

        sort(freq.rbegin(), freq.rend()); // sort in descending order

        int pushes = 0;

        for (int i = 0; i < 26; i++) {
            pushes += (i / 8 + 1) * freq[i]; // Each group of 8 characters requires an additional push
        }

        return pushes;
    }
};