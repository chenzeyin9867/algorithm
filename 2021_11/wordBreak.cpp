#include "head.h"
class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> word_set(wordDict.begin(), wordDict.end());
        if(word_set.count(s)) return true;
        vector<bool> vec(s.size()+1, false);
        if(word_set.count(s.substr(0, 1))) vec[0] = true;
        else    vec[0] = false;
        for(int i = 1; i < s.size(); ++i){
            for(int j = 0; j <= i; ++j) {
                if(word_set.count(std::move(s.substr(i-j, j + 1))) && (i-j-1 <0 ||  vec[i-j-1])){
                    vec[i] = true;
                    break;
                }
            }
        }
        
        return vec[s.size() - 1];
        // return dfs(std::move(s), word_set);
    }

    // bool dfs(string s, unordered_set<string> &word_set){
    //     if(word_set.count(std::move(s))) return true;
    //     if(s.size() == 0) return true;
    //     for(int i = 1; i < s.size(); ++i){
    //         if(word_set.count(std::move(s.substr(0, i))) && dfs(std::move(s.substr(i)), word_set)){
    //             return true;
    //         }
    //     }
    //     return false;
    // }
};