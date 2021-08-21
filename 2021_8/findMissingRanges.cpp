#include "head.h"
class Solution {
public:
    vector<string> findMissingRanges(vector<int>& nums, int lower, int upper) {
            vector<string> result;
            if(nums.size() == 0){
                if(lower==upper) result.emplace_back(to_string(lower));
                else result.emplace_back(to_string(lower) + "->" + to_string(upper));
            }
            int len = nums.size();
            for(int i = 0; i < len; i++){
                // first deals with [lower, nums[0]]
                if(i == 0){
                    if(nums[0] > lower){
                        if(nums[0] == lower+1){
                            result.emplace_back(to_string(lower));
                        }else{
                            result.emplace_back(to_string(lower)+"->"+to_string(nums[0]-1));
                        }
                    }
                }

                else{
                    // deals tje gap between [nums[i-1], nums[i]]
                    if(nums[i] - nums[i-1] > 1){
                        if(nums[i] - nums[i-1] == 2){
                            result.emplace_back(to_string(nums[i]-1));
                        }else{
                            result.emplace_back(to_string(nums[i-1]+1) + "->" + to_string(nums[i]-1));
                        }
                    }
                    
                }
                
                if(i == len - 1){
                    // deals with [nums[len-1], upper]
                    if(nums[i] < upper){
                       if(nums[i] == upper-1){
                            result.emplace_back(to_string(upper));
                        }else {
                            result.emplace_back(to_string(nums[i]+1)+"->"+to_string(upper));
                        }
                    }
                }
            }
            return result;
    }
};

int main(){

}