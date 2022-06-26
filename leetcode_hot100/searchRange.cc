#include "head.h"
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        /* Find the largest number which less than target */
        vector<int> m_result;
        if(nums.size() == 0 ){
            m_result.push_back(-1);
            m_result.push_back(-1);
            return m_result;
        }
        int l = 0, r = nums.size() - 1;
        while(l <= r){
            int mid = l + (r - l)/2;
            if(nums[mid] >= target){
                r = mid - 1;
            }else{
                l = mid + 1;
            }
        }
        /* Search from r + 1 */
        if(r + 1>= nums.size() || nums[r + 1] != target){
            m_result.push_back(-1);
            m_result.push_back(-1);
            return m_result;
        }else{
            /* nums[r+1] == target */
            m_result.push_back(r + 1);
            int t = r + 1;
            while(t < nums.size() && nums[t] == target){
                ++t;
            }
            m_result.push_back(t - 1);
        }
        return m_result;
    }
};