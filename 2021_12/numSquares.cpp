/**
 * @brief       find the minimal number of squares to composite a number, consider using dp
 * @author 		chenzeyin (chenzeyin9867@buaa.edu.cn)
 * @date		2021-12-02
 */
#include "head.h"
class Solution {
public:
    int numSquares(int n) {
        vector<int> dp(n+1, 0);
        dp[0] = 0;
        dp[1] = 1;
        for(int i = 2; i <= n; ++i){
            int cur = 10000;
            if(i == ((int)sqrt(i) * (int)sqrt(i))) {
                dp[i] = 1;
                continue;
            }
            for(int j = 1; j < sqrt(i); ++j){
                cur = min(cur, dp[i - j * j] + 1);
            }   
            dp[i] = cur;
        }
        return dp.back();
    }
};

int main(){
    Solution s;
    // cout << sqrt(11)<< endl;
    for(int i = 1; i < 20; ++i){
        cout << "ind:" << i << " nums:" << s.numSquares(i) << endl;
    }
    return 0;
}