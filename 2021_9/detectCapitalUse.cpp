#include "head.h"
class Solution {
public:
    bool detectCapitalUse(string word) {
        int Capital = 0;
        if(word[0]>='A' && word[0] <='Z')Capital = 1;
        else Capital = 0;
        int tmp = 0;
        int capitalCnt = 0;
        int lowCaseCnt = 0;
        for(auto c: word){
            if(c >= 'A' && c <= 'Z') ++capitalCnt;
            else ++lowCaseCnt;
            // if(tmp != Capital) return false;
        }
        if(Capital){
            return capitalCnt == word.size() || capitalCnt == 1;
        }else{
            return capitalCnt == 0;
        }
        // return true;
    }
};