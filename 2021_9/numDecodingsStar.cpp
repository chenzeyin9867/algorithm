#include "head.h"
class Solution {
public:
    int numDecodings(string s) {
        if(s.size() == 1){
            if(s[0] == '*') return 9;
            if(s[0] == '0') return 0;
            return 1;
        }
        long long div = pow(10, 9)  + 7;
        // iterater to deal with the num
        reverse(s.begin(), s.end());
        // using dynamic programing
        // can't use recursive function for the len of str is 10^5
        vector<long long> dp(s.size() + 1);
        if(s[0] == '*') dp[0] = 9;
        else if(s[0] == '0') dp[0] = 0;
        else dp[0] = 1; 
        for(int i = 1; i < s.size(); ++ i){
            char c = s[i];
            if(c == '0') dp[i] = 0;
            else if(c == '*'){
                long long cnt1 = 0; // see * as one word
                if(s[i-1] != '0') cnt1 = 9;
                long long cnt2 = 0; // use * and i+1 as a word only when c == '1' or c == '2'
                if(s[i - 1] > '6' && s[i-1] <= '9'){
                    cnt2 = 1; // only 16-19
                }else if(s[i-1] >= '0' && s[i-1] <= '6'){
                    cnt2 = 2; // 21-26 + 11-16
                }else if(s[i-1] == '*'){
                    // ** can represent
                    cnt2 = 15;
                }
                if(i >= 2) dp[i] = cnt2 * dp[i-2];
                else dp[i] = cnt2;
                dp[i] += dp[i-1] * cnt1;

                // dp[i] = (dp[i-2] + cnt2 + dp[i-1] + cnt1);
                dp[i] %= div;
            } else{
                // c >= '1' && c<='9'
                long long cnt1 = 0;
                if(s[i-1] != '0') cnt1 = 1;
                long long cnt2 = 0;
                if((c == '1' && (s[i-1] >= '0' && s[i-1] <= '9'))|| (c == '2' && s[i-1] <= '6' && s[i-1] >= '0')){
                    cnt2 = 1;
                }else if(s[i-1] == '*'){
                    if(c == '1'){
                        cnt2 = 9;
                    }else if(c == '2'){
                        cnt2 = 6;
                    }
                }
                if(i >= 2) dp[i] = cnt2  * dp[i-2];
                else dp[i] = cnt2;
                dp[i] += dp[i-1] * cnt1;
                dp[i] %= div;
             }
             cout << dp[i] << endl;
        }
        
        return dp[s.size() - 1];
    }
};