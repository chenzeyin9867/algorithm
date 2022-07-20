#include "head.h"
/* n is the size of nums, find the disappeared numbers. */
class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        vector<int> result;
        unordered_set<int> number_set;
        for(auto &n : nums){
            number_set.insert(n);
        }

        for(int i = 1; i <= nums.size(); ++i){
            if(number_set.find(i) == number_set.end()){
                result.push_back(i);
            }
        }
        return result;
    }
};