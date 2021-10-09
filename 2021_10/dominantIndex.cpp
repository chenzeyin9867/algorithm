#include "head.h"
class Solution {
public:
    int dominantIndex(vector<int>& nums) {
        if(nums.size() == 1) return 0;
        int max = -1;
        int second = -1;
        int index = -1;
        for(auto n : nums){
            if(max == -1) {
                max = n;
                // index = 
                // second = n;
            }else{
                if(n > max){
                    second = max;
                    max = n;
                }else{
                    if(n > second) second = n;
                }
            }
        }
        if(max >= 2 * second) return find(nums.begin(), nums.end(), max) - nums.begin();
        else return -1;
    }
};