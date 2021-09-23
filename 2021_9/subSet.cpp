#include "head.h"
class Solution {
public:
    vector<vector<int>> result;
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
    
        if(nums.empty()) return result;
        sort(nums.begin(), nums.end());
        vector<int> cur;
        cur.emplace_back(0);
        gatherSet(cur, 1, nums);
        cur.pop_back();
        gatherSet(cur, 1, nums);
        for(auto &k: result){
            for(auto &m: k){
                m = nums[m];
            }
        }
        return result;
    }

    void gatherSet(vector<int>& cur, int index, vector<int>& nums){
        // if index >= cur.size()
        if(index >= nums.size()) 
        {
            // if(cur.size()>0)
            // for(auto k : cur){
            //     cout << " " << k;
            // }
            // cout << endl;
            result.emplace_back(cur);
            return;
        }
        // if choose nums[index], judge whether the nums[index-1] == nums[index] 
        if(nums[index] == nums[index-  1] && (cur.size() == 0 ||  cur.back() != index - 1)){
            // This situation, can't choose nums[index]
            gatherSet(cur, index+1, nums);
        }else{
            //choose
            cur.emplace_back(index);
            gatherSet(cur, index+1, nums);
            cur.pop_back();
            gatherSet(cur, index+1, nums);
        }
    }
    
    

};

int main(){
    Solution s;
    vector<int> nums{5,5,5,5,5};
    vector<vector<int>> result = s.subsetsWithDup(nums);
    for(auto k : result){
        printVector(k);
    }
    cout << result.size() << endl;
    return 0;
}