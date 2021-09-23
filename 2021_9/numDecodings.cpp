#include "head.h"
class Solution {
public:
    int numDecodings(string s) {
        int len = s.size();
        vector<int> dp(len, 0);
        dp[0] = 1;
        if(s.back() == '0'){
            dp[0] = 0;
        }
        for(int i = 1; i < s.size(); ++i){
            char cur = s[s.size() - 1 - i];
            char prev = s[s.size() - i];
            int num1 = 0;
            int num2 = 0;
            // num2 = dp[i-1];
            // cout << cur << endl;
            if(cur != '0'){
                // cout << "here" << endl;
                num1 = dp[i - 1];
                if(stoi(s.substr(s.size() - 1 - i, 2)) <= 26){
                    if(i < 2){
                        num2 = 1;
                    }else{
                        num2 = dp[i -2 ];
                    }
                }
            }
            dp[i] = num1 + num2;
            cout << num1 << " " << num2 << endl;
         }
        return dp.back();
    } 
};

int main(){
    Solution s;
    string num = "10";
    cout << s.numDecodings(num) << endl;
    return 0;
}