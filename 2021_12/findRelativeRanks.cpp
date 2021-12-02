/**
 * @brief       find relative ranks
 * @author 		chenzeyin (chenzeyin9867@buaa.edu.cn)
 * @date		2021-12-02
 */
#include "head.h"

class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        map<int, int> index;
        for(int i = 0; i < score.size(); ++i){
            index.insert(make_pair(score[i], i));
        }
        vector<string> rets(score.size());
        int cur_rank = 1;
        int prev_score = -1;
        for(auto it = index.crbegin(); it != index.crend(); ++it){
            string cur;
            if(cur_rank == 1){
                cur = "Gold Medal";
            }else if(cur_rank == 2){
                cur = "Silver Medal";
            }else if(cur_rank == 3){
                cur = "Bronze Medal";
            }else{
                cur = to_string(cur_rank);
            }
            ++cur_rank;
            rets[it->second] = cur;
        }
        return rets;
    }
};