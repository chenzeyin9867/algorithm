#include "head.h"
class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size() != t.size()) return false;
        map<char, int> cnt;
        for(auto i : s){
            cnt[i]++;
        }
        for(auto i : t){
            if(cnt[i] == 0) return false;
            cnt[i]--;
        }

        auto iter = cnt.begin();
        while(iter != cnt.end()){
            if(iter->second!=0){
                return false;
            }
            iter++;
        }
        return true;
    }
};

