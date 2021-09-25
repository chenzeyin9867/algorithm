#include "head.h"
class Solution {
public:
    int calPoints(vector<string>& ops) {
        vector<int> nums;
        int result = 0;
        for(int i = 0; i < ops.size(); ++i){
            string tmp = ops[i];
            if(tmp == "+"){
                int cur = nums.back() + nums[nums.size() - 2];

                result += cur;
                nums.emplace_back(cur);
            }else if(tmp == "D"){
                int cur = 2 * nums.back();
                nums.emplace_back(cur);
                result += cur;
            }else if(tmp == "C"){
                int cur = nums.back();
                nums.pop_back();
                result -= cur;
            }else{
                int cur = stoi(tmp);
                nums.emplace_back(cur);
                result += cur;
            }
        }
        return result;
    }
};