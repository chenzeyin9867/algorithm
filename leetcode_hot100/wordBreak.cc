#include "head.h"
/*  A solution to determine that whether the s can be break into
    words in wordDict. Consider to transfer this problem into a
    Dynamic Programming one. */
class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        auto wordDictSet = unordered_set <string> ();
        for (auto word: wordDict) {
            wordDictSet.insert(word);
        }

        auto dp = vector <bool> (s.size() + 1);
        dp[0] = true;
        for (int i = 1; i <= s.size(); ++i) {
            for (int j = 0; j < i; ++j) {
                if (dp[j] && wordDictSet.find(s.substr(j, i - j)) != wordDictSet.end()) {
                    dp[i] = true;
                    break;
                }
            }
        }

        return dp[s.size()];
    }
};

int main(){
    Solution s;
    string s1 = "catsandog";
    vector<string> v_str = {"cats", "dog", "sand", "and"};
    std::cout << s.wordBreak(s1, v_str) << std::endl;
    return 0;
}