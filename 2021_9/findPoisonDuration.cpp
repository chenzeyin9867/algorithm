#include "head.h"
class Solution {
public:
    int findPoisonedDuration(vector<int>& timeSeries, int duration) {
        long long  durationSum = 0;
        long long  gap = 0;
        for(int i = 1; i < timeSeries.size(); i++){
            gap += (timeSeries[i] - timeSeries[i-1]) >= duration ? 0 : (duration - (timeSeries[i] - timeSeries[i-1])); // if gap < duration, then minus this part
        }
        return duration * timeSeries.size() - gap;
    }
};