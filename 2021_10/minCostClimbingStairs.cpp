#include "head.h"
class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int len = cost.size();
        vector<int> result(len + 1, 0);
        result.back() = 0;
        for(int i = len - 1; i >= 0; --i){
            if(i == len - 1){
                result[i] = cost[i];
            }else{
                result[i] = cost[i] + min(result[i+1], result[i+2]);
            }
        }
        return min(result[0], result[1]);
    }
};