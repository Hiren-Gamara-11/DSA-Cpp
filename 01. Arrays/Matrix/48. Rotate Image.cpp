/*
==================================================
    48. Rotate Image

    Difficulty: Medium
    Topic: Array, Matrix

    Approach:
    1. Transpose the matrix.
    2. Reverse each row.
    3. This rotates the matrix 90° clockwise.

    Time Complexity: O(n²)
    Space Complexity: O(1)
==================================================
*/

#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();

        // Step 1: Transpose the matrix
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                swap(matrix[i][j], matrix[j][i]);
            }
        }

        // Step 2: Reverse each row
        for (int i = 0; i < n; ++i) {
            reverse(matrix[i].begin(), matrix[i].end());
        }
    }
};
```
