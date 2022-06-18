#include "head.h"
class Solution {
public:
    string longestPalindrome(string s) {
        uint64_t max_length = 0;
        string ret_str;
        int dp[s.size()][s.size()];
        memset(dp, 0, sizeof(dp));
        if(s.size() == 0) return string();
        max_length = 1;
        ret_str = string(1,s[0]);
        for(size_t l = 1; l <= s.size(); ++l){
            for(int i = 0; i + l - 1 < s.size(); ++i){
                /* Test if dp[i][i + l - 1] is Palindrome */
                if(s[i] == s[i + l - 1] && ((l == 1 || l == 2) || (dp[i+1][i + l - 2]))){
                    dp[i][i+l-1] = 1;
                    if(l > max_length){
                        max_length = l;
                        ret_str = s.substr(i, l);
                    }
                }
            }
        }
        return ret_str;
    }
};

int main(){
    Solution s;
    string str;
    cin >> str;
    std::cout << s.longestPalindrome(str) << std::endl;
    return 0;
}