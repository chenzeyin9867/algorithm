#include "head.h"
class Solution {
public:
    int search(vector<int>& nums, int target) {
        // for(int i = 0; i < nums.size(); ++i){
        //     if(target == nums[i]) return i;
        // }
        if(nums.size() == 0) return -1;
        long long l = 0, r = nums.size() - 1;
        while(l <= r){
            if(target == nums[l]) return l;
            if(target == nums[r]) return r;
            long long mid = l + (r - l) / 2;
            if(nums[mid] == target)
            {
                return mid;
            }else if(target < nums[mid]){
                if(nums[mid] > nums[r]) // in reverse part
               {
                   if(target > nums[l]){
                       r = mid - 1;
                   }else{
                       l = mid + 1;
                   }
               }else{ // mormal part
                   r = mid - 1;     
               }
            }else if(target > nums[mid]){
                if(nums[mid] > nums[r]){
                    l = mid + 1;
                }else{
                    if(target > nums[r]){
                        r = mid - 1;
                    }else{
                        l = mid + 1;
                    }
                }
            }
        }
        return -1;
    }
};