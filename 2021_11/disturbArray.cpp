/**
 * @file		disturbArray.cpp
 * @brief       
 * @author 		chenzeyin (chenzeyin9867@buaa.edu.cn)
 * @date		2021-11-22
 * @copyright	Copyright (c) 2021  chenzeyin9867
 */
/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * vector<int> param_1 = obj->reset();
 * vector<int> param_2 = obj->shuffle();
 */
#include "head.h"

class Solution {
public:
    Solution(vector<int>& nums) : origin_(nums), id_(0, nums.size() - 1) {

    }
    
    vector<int> reset() {
        return origin_;
    }
    
    vector<int> shuffle() {
        // int len = origin_.size();
        vector<int> result;
        unordered_set<int> num_set;
        for(int i = 0; i < origin_.size(); ++i){
            while(1){
                int rand_num = id_((e_));
                if(!num_set.count(rand_num)){
                    cout << rand_num << endl;
                    num_set.insert(rand_num);
                    result.emplace_back(origin_[rand_num]);
                    break;
                }
            }
        }
        return result;
    }

    vector<int> vec_;
    vector<int> origin_;
    static default_random_engine e_;
    uniform_int_distribution<int> id_;
};
default_random_engine Solution::e_(time(0));
int main(){
    vector<int> nums{1,2,3,4};
    Solution s(nums);
    s.shuffle();
    return 0;
    
}