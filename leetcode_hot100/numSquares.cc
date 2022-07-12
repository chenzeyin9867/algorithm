#include "head.h"
/* Return the least number sumed as the n */
class Solution {
public:
    int numSquares(int n) {
        vector<int> dp(n+1, 100000);
        if(n <= 1) return 1;
        dp[1] = 1;
        for(int i = 2; i <= n; ++i){
            int sqr = sqrt(i);
            if(sqr * sqr == i){
                dp[i] = 1;
                continue;
            }
            /* Iterator from 1 to i-1 */
            int sqr = sqrt(i);
            for(int j = 1; j < sqr; ++j){
                dp[i] =std::min(1 + dp[i- j * j], dp[i]);
            }
        }
        return dp[n];
    }
};

int main(){
    Solution s;
    int in;
    while(cin >> in)
        cout << s.numSquares(in) << endl;
    return 0;
}