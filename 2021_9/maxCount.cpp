#include "head.h"
class Solution {
public:
    int maxCount(int m, int n, vector<vector<int>>& ops) {
        int minM = 100000;
        int minN = 100000;
        if(ops.empty()) return m * n;
        for(auto op : ops){
            int curM = op[0];
            int curN = op[1];
            minM = curM < minM ? curM : minM;
            minN = curN < minN ? curN : minN;
        }
        return minN * minM;
    }
};