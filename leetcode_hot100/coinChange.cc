#include "head.h"
/* Calculate the minimal number of coins to form the amount. */
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        if(amount < 1) return 0;
        vector<int> dp(amount + 1, 0);
        dp[0] = 0;
        for(auto &t : coins){
            if(t > amount) continue;
            dp[t] = 1;
        }
        /* dynamic programming */
        for(int i = 1; i <= amount; ++i){
            for(int c : coins){
                if(i >= c){
                    // dp[i] = std::min(dp[i-c], dp[i]);
                    if(dp[i-c] != 0){
                        if(dp[i] == 0){
                            dp[i] = dp[i-c] + 1;
                        }else{
                            dp[i] = std::min(dp[i], dp[i-c] + 1);
                        }
                    }
                }
            }
        }
        if(dp[amount] == 0) return -1;
        return dp[amount];
    }
};

int main(){
    Solution s;
    vector<int> coins{2};
    cout << "least : " << s.coinChange(coins, 1) << endl;
    return 0;
}