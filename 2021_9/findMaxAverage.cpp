#include "head.h"
class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        double ave = 0.0;
        for(int i = 0; i < k; i++){
            ave += nums[i];
        }   
        double maxAve = ave; 
        for(int i = 1; i < nums.size() - k + 1; i++){
            ave = ave + nums[i + k - 1] - nums[i-1];
            if(ave > maxAve) maxAve = ave;
        }
        return maxAve / k;
    }
};