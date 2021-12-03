/**
 * @brief Negative k times, return the maximal sum
 */
#include "head.h"
class Solution {
public:
    int largestSumAfterKNegations(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        reverse(nums.begin(), nums.end());
        
        for(int i = nums.size() - 1; i >= 0; --i){
            if(nums[i] <= 0 && k > 0){
                nums[i] = -nums[i];
                --k;
            }else if(nums[i] > 0 && k > 0){
                k = k % 2;
                if(k == 0){
                    break; // just iter
                }else{
                    // n == 1, choose the smallest num to change to negtive
                    if(i < nums.size() - 1){
                        if(nums[i] < nums[i+1]){
                            nums[i] = -nums[i];
                        }else{
                            nums[i+1] = - nums[i+1];
                        }
                    }else{
                        nums[i] = -nums[i];
                    }
                }
                --k;
                break;
            }
        }
        if(k > 0){
            k = k % 2;
            if(k == 0){
            }else{
                if(1 < nums.size() - 1){
                    if(nums[0] < nums[1]){
                        nums[0] = -nums[0];
                        }else{
                            nums[1] = - nums[1];
                        }
                    }else{
                        nums[0] = -nums[0];
                    }
                }
        }
        int acc = 0;
        // for(auto a: nums){
        //     cout << a << endl;
        // }
        return std::accumulate(nums.begin(), nums.end(), acc);
    }
};