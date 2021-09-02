#include "head.h"
class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        if(ransomNote.size()>magazine.size()) return false;
        unordered_map<char, int> cnt;
        for(auto c:magazine){
            cnt[c]++;
        }
        for(auto c:ransomNote){
            if(!cnt[c]) return false;
            else cnt[c]--;
        }
        return true;
    }
};