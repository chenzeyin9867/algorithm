/* This is a program to compute the max prices */
#include "head.h"
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size() == 1){
            return 0;
        }
        int low_price, high_prices;
        low_price = prices[0];
        int max_profit = 0;
        for(int i = 1; i < prices.size(); ++i){
            low_price = std::min(low_price, prices[i]);
            max_profit = std::max(max_profit, prices[i] - low_price);
        }
        return max_profit;
    }
};