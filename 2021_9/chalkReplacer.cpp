#include "head.h"
class Solution {
public:
    int chalkReplacer(vector<int>& chalk, int k) {
        vector<long long> sum;
        for(int i = 0; i < chalk.size(); ++i){
            if(i == 0) sum.emplace_back(chalk[0]);
            else {
                long prev = sum.back();
                sum.emplace_back(prev + chalk[i]);
            }

        }

        int index = 0;
        k = k % sum.back();
        for(int i = 0; i < sum.size(); i++){
            if(k < sum[i]){
                index = i;
                break;
            }
        }
        return index;
    }
};