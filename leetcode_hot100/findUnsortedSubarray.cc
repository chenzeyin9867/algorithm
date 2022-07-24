#include "head.h"
/* Find the shortest array sorting which makes the whole a sorted one */
class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        vector<int> least_array(nums.size(), 0);
        vector<int> great_array(nums.size(), 0);
        // Least array records the minimal number from cur to last
        least_array.back() = nums.back();
        for(int i = nums.size() - 2; i >= 0; --i){
            least_array[i] = std::min(nums[i], least_array[i+1]);
        }
        // great_array reverse
        great_array.front() = nums.front();
        for(int i = 1; i < nums.size(); ++i){
            great_array[i] = std::max(great_array[i-1], nums[i]);
        }
        int l = 0, r = 0;
        while(l < nums.size()){
            if(nums[l] > least_array[l]){
                break;
            }
            ++l;
        }
        if(l >= nums.size()) return 0;
        r = nums.size() - 1;
        while(r >= 0){
            if(nums[r] < great_array[r]){
                break;
            }
            --r;
        }
        l = l - 1;
        r = r + 1;
        return r - l - 1;
    }
};