#include "head.h"
/* Found the num more than half of the nums */
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int master = nums[0];
        int master_cnt = 1;
        for(int i = 1; i < nums.size(); ++i){
            if(master_cnt == 0){
                master = nums[i];
                master_cnt++;
                continue;
            }
            if(nums[i] == master){
                master_cnt++;
            }else{
                master_cnt--;
            }
        }
        return master;
    }
};