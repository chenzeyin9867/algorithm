/**
 * @brief       whether ransomNote can be consisted by chars in magzine
 * @author 		chenzeyin (chenzeyin9867@buaa.edu.cn)
 * @date		2021-12-04
 */
#include "head.h"
class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map <int, int> mags;
        for(auto c : magazine){
            ++mags[c];
        }
        for(auto c: ransomNote){
            if(mags.count(c)){
                --mags[c];
                if(mags[c] == 0){
                    mags.erase(c);
                }
            }
            else{
                return false;
            }
        }
        return true;
    }
};