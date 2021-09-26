#include "head.h"
class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {
        unordered_map<int, int> cnt;
        // int degreeIndex = -1;
        int maxCnt = -1;
        for(auto t: nums){
            ++cnt[t];
            if(cnt[t] > maxCnt){
                // degreeIndex = t;
                maxCnt = cnt[t];
            }
        }
        unordered_set<int> numSet;
        for(auto m : cnt){
            if(m.second == maxCnt){
                numSet.emplace(m.first);
            }
        } 
        // t is the degree number
        int minLength = INT32_MAX;
        for(auto degreeIndex : numSet){

            int l = 0;
            int r = nums.size() - 1;
            while(nums[l] != degreeIndex){
                ++l;
            }
            while(nums[r] != degreeIndex){
                --r;
            }
            if(r - l + 1 < minLength ){
                minLength = r - l + 1;
            }
        }

        return minLength;
    }
};