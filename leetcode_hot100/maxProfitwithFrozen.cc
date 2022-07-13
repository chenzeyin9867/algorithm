#include "head.h"
/* If sold stock at day t, you cannot buy stock at day t+1 */
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        /* three state: 0:frozen   1:buy    2:sold  */
        vector<vector<int>> profits(prices.size() + 1, vector<int>(3, 0));
        for(int i = 1; i < prices.size(); ++i){
            /* If buy stock at i, then must not sold at i-1 */
            profits[i][1] = std::max(profits[i-1][0], 
                i >=2 ? profits[i-2][2] : 0);
             
            /* If froze this day, just = yesterday */
            profits[i][0] = std::max(profits[i-1][0],
                    std::max(profits[i-1][1], profits[i-1][2]));

            /* If sold this day, loop compute then */
            for(int j = 0; j < i; ++j){
                profits[i][2] = std::max(profits[i][2], 
                        profits[j][1] + prices[i] - prices[j]);
            }
        }
        int sz = prices.size() - 1;
        return std::max(profits[sz][0], std::max(profits[sz][1], 
            profits[sz][2]));

    }
};

int main(){
    Solution s;
    vector<int> prices {1, 2, 3, 0, 2};
    std::cout << "maxPrices: " << s.maxProfit(prices) << endl;
    return 0;
}
    

// class Solution {
// public:
//     int maxProfit(vector<int>& prices) {
//         if (prices.empty()) {
//             return 0;
//         }

//         int n = prices.size();
//         // f[i][0]: 手上持有股票的最大收益
//         // f[i][1]: 手上不持有股票，并且处于冷冻期中的累计最大收益
//         // f[i][2]: 手上不持有股票，并且不在冷冻期中的累计最大收益
//         vector<vector<int>> f(n, vector<int>(3));
//         f[0][0] = -prices[0];
//         for (int i = 1; i < n; ++i) {
//             f[i][0] = max(f[i - 1][0], f[i - 1][2] - prices[i]);
//             f[i][1] = f[i - 1][0] + prices[i];
//             f[i][2] = max(f[i - 1][1], f[i - 1][2]);
//         }
//         return max(f[n - 1][1], f[n - 1][2]);
//     }
// };

