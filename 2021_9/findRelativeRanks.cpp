#include "head.h"
bool cmp(pair<int, int> p1, pair<int, int>p2){
    return p1.second > p2.second;
}
class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        string name[4] = {"","Gold Medal", "Silver Medal", "Bronze Medal"};
        vector<pair<int, int> > ranks;
        vector<string> result;
        for(int i = 0; i < score.size(); i++){
            ranks.emplace_back(make_pair(i, score[i]));
        }
        sort(ranks.begin(), ranks.end(), cmp);
        unordered_map<int, int> rankIndex;
        for(int i = 0; i < ranks.size(); ++i ){
            rankIndex[ranks[i].first] = i+1;
        }
        for(int i = 0; i < score.size(); ++i){
            if(rankIndex[i] <= 3){
                result.emplace_back(name[rankIndex[i]]);
            }else{
                result.emplace_back(to_string(rankIndex[i]));
            }
        }
        return result;
    }
};

int main(){
    Solution s;
    vector<int> scores{5,4,3,2,1};
    auto rt = s.findRelativeRanks(scores);
    printVector(rt);
    return 0;
}