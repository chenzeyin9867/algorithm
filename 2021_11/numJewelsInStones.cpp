#include "head.h"
class Solution {
public:
    int numJewelsInStones(string jewels, string stones) {
        unordered_set<char> jewelsCategory;
        for(auto c: jewels){
            jewelsCategory.insert(c);
        }
        int cnt = 0;
        for(const char &t : stones){
            if(jewelsCategory.find(t) != jewelsCategory.end()){
                ++cnt;
            }
        }
        return cnt;
    }
};