#include "head.h"
class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> result;
        if(nums.size() == 0) return result;
        int start = nums[0];
        int prev = start;
        for(int i = 1; i < nums.size(); i++){
           int cur = nums[i];
           if(cur == nums[i-1]+1){
               prev = cur;
           }else{
               // cur != nums[i-1] + 1
               if(prev == start) // only one word
                    result.emplace_back(to_string(start));
                else{
                    result.emplace_back(to_string(start) + "->" + to_string(prev));
                }
                prev = start = cur;
           }
           
        }
        if(prev == start) // only one word
                result.emplace_back(to_string(start));
        else{
               result.emplace_back(to_string(start) + "->" + to_string(prev)); 
        }
        return result;
    }

};

int main(){
    Solution s;
    vector<int> nums{0,2,3,4,6,8,9};
    vector<string> r = s.summaryRanges(nums);
    printVector(r);
    return 0;
    
}