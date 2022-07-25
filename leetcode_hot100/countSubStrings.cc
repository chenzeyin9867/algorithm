#include "head.h"
/* Count the total number of all the palindromes. */
class Solution {
public:
    int countSubstrings(string s) {
        int cnt = 0;
        vector<vector<int>> dp(s.size(), vector<int>(s.size(), 0));
        for(int i = 0; i < s.size(); ++i){
            dp[i][i] = 1;
            ++cnt;
        }
        for(int l = 2; l <= s.size(); ++l){
            for(int idx = 0; idx + l - 1 < s.size(); ++idx){
                int i = idx, j = idx + l - 1;
                if(s[i] != s[j]){
                    continue;
                }
                if(j - i == 1 || j - i == 2 || dp[i+1][j-1]){
                    dp[i][j] = 1;
                    ++cnt;
                }
            }
        }
        return cnt;
    }
};

int main(){
    Solution s;
    string input;
    while(cin >> input)
        cout << "Palindrome cnt for " << input << " is: " << s.countSubstrings(input) << endl;
    return 0;
}