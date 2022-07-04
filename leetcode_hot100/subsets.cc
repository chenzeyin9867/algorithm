#include "head.h"
class Solution {
public:
    vector<vector<int>> m_ret;
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> m_tmp;
        dfs(nums, m_tmp, 0);
        return m_ret;
    }

    void dfs(vector<int>& nums, vector<int>& tmp, int idx){
        if(idx == nums.size()){
            m_ret.push_back(tmp);
            return;
        }
        /* Not choose nums[idx]. */
        dfs(nums, tmp, idx + 1);
        /* Choose nums[idx]. */
        tmp.push_back(nums[idx]);
        dfs(nums, tmp, idx + 1);
        tmp.pop_back();
        return;
    }
};

int main(){
    Solution s;
    vector<int> nums{1, 2, 3, 4};
    auto m_ret = s.subsets(nums);
    for(auto &vec : m_ret){
        for(auto t : vec){
            cout << t << " ";
        }
        std::cout << std::endl;
    }
    return 0;
}