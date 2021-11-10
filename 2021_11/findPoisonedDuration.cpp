#include "head.h"
class Solution {
public:
    int findPoisonedDuration(vector<int>& timeSeries, int duration) {
        int sum = 0;
        int currentPoins = 0;
        for(auto &t : timeSeries){
            if(currentPoins == 0){
                sum += duration;
                currentPoins = t + duration;
            }else{
                if(t > currentPoins) {
                    sum += duration;
                    currentPoins = t + duration;
                }
                else{
                    sum += duration + t - currentPoins;
                    currentPoins = duration + t;
                }

                // --currentPoins;
            }
        }
        return sum;
    }
};