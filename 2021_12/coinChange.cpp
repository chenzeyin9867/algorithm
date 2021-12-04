#include "head.h"
#define MAXNUM 10000000
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        sort(coins.begin(), coins.end());
        vector<int> dp(amount + 1, 0);
        dp[0] = 0;
        for(auto c : coins){
            if(c <= amount)
            dp[c] = 1;
        }
        for(int i = 1; i <= amount; ++i){
            int min_num = MAXNUM;
            if(dp[i] == 0){
                for(auto &c : coins){
                    if(c >= i) break;
                    else{
                        if(dp[i - c] != -1){
                            min_num = min(min_num, dp[i-c] + 1);
                        }
                        if(i % c == 0 && dp[c]!= -1){
                            min_num = min(min_num, i / c * dp[c]);
                        }
                    }
                }
                if(min_num == MAXNUM){
                    dp[i] = -1;
                }else{
                    dp[i] = min_num;
                }
            }

            // cout << "i: " << i << " dp: " <<  dp[i] << endl;
        }
        return dp[amount];
    }
};