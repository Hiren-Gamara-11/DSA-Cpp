/*
========================================
121. Best Time to Buy and Sell Stock
========================================

Approach:
- Track the minimum buying price seen so far.
- Calculate the profit for each day.
- Update the maximum profit if the current profit is higher.

Time Complexity: O(n)
Space Complexity: O(1)

*/

#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        long long start = prices[0], profit = 0;
        for(int i=1; i<prices.size(); i++){
            long long minus = prices[i] - start;
            profit = max(profit, minus);
                if(prices[i] < start){
                    start = prices[i];
                }
        }
        return profit;    
    }
};