#include "head.h"
class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        vector<int> visit(10001, 0);
        vector<int> result;
        int duplicate = 0;
        long long sum = 0;
        for(auto n : nums){
            if(visit[n] == 1) duplicate = n; 
            visit[n] = 1;
            sum += n;
        }
        result.emplace_back(duplicate);
        sum -= duplicate;
        result.emplace_back((int)((1+nums.size())*nums.size() / 2 - sum));
        return result;
    }
};
