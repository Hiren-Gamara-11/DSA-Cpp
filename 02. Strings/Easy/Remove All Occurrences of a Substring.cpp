/*
==================================================
Problem      : Remove All Occurrences of a Substring
LeetCode     : 1910
Difficulty    : Medium
Topic         : String
Approach      : find() + erase()

Time Complexity  : O(n^2) - Worst Case
Space Complexity : O(1) - Auxiliary Space
==================================================
*/

#include <string>
using namespace std;

class Solution {
public:
    string removeOccurrences(string s, string part) {
        size_t pos; // In short: size_t pos; creates a variable to store the index returned by s.find(part). 
                    // size_t is the standard unsigned integer type used for string/container sizes and indices in C++.

        while ((pos = s.find(part)) != string::npos) { // string::npos means "not found"
            s.erase(pos, part.length());
        }

        return s;
    }
};