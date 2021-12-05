#include "head.h"
bool cmp(pair<int,int> a, pair<int,int> b){
    return a.second > b.second;
}
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        // std::sort(nums.begin(), nums.end(), cmp);
        // for(auto i : nums) cout << i << endl;
        unordered_map <int, int> count_map;
        for(auto &n: nums){
            ++count_map[n];
        }
        vector<pair<int, int>> p_l;
        for(auto &it: count_map){
            p_l.emplace_back(it.first, it.second);
        }

        std::sort(p_l.begin(), p_l.end(), cmp);
        vector<int> ret;
        for(int i = 0; i < k; ++i){
            ret.push_back(p_l[i].first);
        }
        return ret;
    }
};
