#include "head.h"
class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        if(nums.size() == 1) return 0;
        if(nums[0] > nums[1]) return 0;
        if(nums.size()>=2 && nums.back() > nums[nums.size()-2]) return nums.size()-1; 
        // if(nums.back() > nums[nums.size() - 2 ])
        int l = 0;
        int r = nums.size() - 1;
        while(l <= r){
            int mid = l + (r - l)/2;
            if(mid == 0) {
                if(nums[mid] > nums[mid + 1]) return mid;
                else l = mid + 1;  
            }else if(mid == nums.size() - 1){
                if(nums[mid] > nums[mid - 1]) return mid;
                else r = mid - 1;
            }else{
                if(nums[mid] > nums[mid - 1] && nums[mid] > nums[mid + 1]){
                    return mid;
                }else if(nums[mid] > nums[mid - 1]){
                    l = mid + 1;
                }else{
                    r = mid - 1;
                }
            }
        }
        return l;
    }
};