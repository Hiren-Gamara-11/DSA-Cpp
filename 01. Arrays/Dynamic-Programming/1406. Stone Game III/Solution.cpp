#include <vector>
#include <climits>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
    string stoneGameIII(vector<int>& stoneValue) {
        int n = stoneValue.size();

        // dp[i] = Maximum score difference current player can achieve
        vector<int> dp(n + 1, 0);

        for (int i = n - 1; i >= 0; i--) {
            int best = INT_MIN;
            int runningSum = 0;

            // Try taking 1, 2, or 3 stones
            for (int k = 1; k <= 3; k++) {
                if (i + k > n)
                    break;

                runningSum += stoneValue[i + k - 1];

                best = max(best, runningSum - dp[i + k]);
            }

            dp[i] = best;
        }

        if (dp[0] > 0)
            return "Alice";
        if (dp[0] < 0)
            return "Bob";

        return "Tie";
    }
};