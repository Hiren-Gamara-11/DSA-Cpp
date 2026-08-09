/*
# 48. Rotate Image

**Difficulty:** Medium
**Topic:** Array, Matrix, Simulation

## Approach

1. **Transpose the matrix**

   * Swap `matrix[i][j]` with `matrix[j][i]`.
   * Only iterate `j` from `i + 1` to avoid swapping elements twice.

2. **Reverse every row**

   * After transposing, reverse each row.
   * This produces a **90° clockwise rotation**.

### Complexity

* **Time:** `O(n²)`
* **Space:** `O(1)` — in-place rotation

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
