#include "head.h"
bool cmp(const pair<string, int>& p1, const pair<string, int>&p2){
    return p1.second < p2.second;
}
class Solution {
public:
    vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
        unordered_map<string, int> restaurantCnt;
        vector<string> result;
        vector<pair<string, int>> indexCnt;
        for(int i = 0; i < list1.size(); ++i){
            restaurantCnt[list1[i]] = (i + 1);
        }
        for(int i =0; i< list2.size(); ++i){
            if(restaurantCnt.count(list2[i])){
                indexCnt.emplace_back(make_pair(list2[i], restaurantCnt[list2[i]] + i + 1));
            }
        }
        sort(indexCnt.begin(), indexCnt.end(), cmp);
        int minIndex = 1000000;
        for(auto t: indexCnt){
            if(t.second <= minIndex){
                minIndex = t.second;
                result.emplace_back(t.first);
            }else{
                break;
            }
        }
        return result;
    }
}; 