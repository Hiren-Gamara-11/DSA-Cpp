#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maxLen(vector<int>& arr) {
        int maxLen = 0;

        // prefix sum -> first index
        unordered_map<int, int> sumIndexMap;

        int sum = 0;

        for (int i = 0; i < arr.size(); i++) {
            sum += arr[i];

            if (sum == 0) {
                maxLen = i + 1;
            }
            else if (sumIndexMap.find(sum) != sumIndexMap.end()) {
                maxLen = max(maxLen, i - sumIndexMap[sum]);
            }
            else {
                sumIndexMap[sum] = i;
            }
        }

        return maxLen;
    }
};