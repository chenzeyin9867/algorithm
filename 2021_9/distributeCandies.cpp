#include "head.h"
class Solution {
public:
    int distributeCandies(vector<int>& candyType) {
        // int candyNum = candyType.size() / 2;
        int sisterNum = candyType.size() / 2;
        unordered_map<int, int> candiesMap;
        for(auto cdy: candyType){
            candiesMap[cdy]++;
        }
        if(candiesMap.size() > sisterNum){
            return sisterNum;
        }else{
            return candiesMap.size();
        }
        
    }
};