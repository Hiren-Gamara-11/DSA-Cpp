// ============================================================
// LeetCode rgb(10, 158, 10) - Best Time to Buy and Sell Stock
//
// Approach:
// Keep track of the minimum price seen so far and calculate
// the profit if the stock is sold at the current price.
// Update the maximum profit whenever a better profit is found.
//
// Time Complexity: O(n)
// Space Complexity: O(1)
// ============================================================

#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int minPrice = prices[0];
        int maxProfit = 0;

        for (int price : prices)
        {
            minPrice = min(minPrice, price);
            maxProfit = max(maxProfit, price - minPrice);
        }

        return maxProfit;
    }
};