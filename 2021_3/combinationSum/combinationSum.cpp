#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;
class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ret_result; // the final answer
        std::sort(candidates.begin(), candidates.end());
        vector<int> curList;
        combina_iterate(curList, candidates, target, ret_result);
        return ret_result;
    }
    
    void combina_iterate(vector<int> &cur_list, vector<int> candidates, int target, vector<vector<int>>&final_list){
        int sum = accumulate(cur_list.begin(), cur_list.end(), 0);
        if(sum == target){
            final_list.push_back(cur_list);
            return ;
        } else{
            if(sum + candidates[0] <= target){
                cur_list.push_back(candidates[0]);
                combina_iterate(cur_list, candidates, target, final_list);
                cur_list.pop_back();
            } 
            if(candidates.size() > 1 && candidates[1] + sum <= target){
                // cur_list.push_back(candidates[1]);
                vector<int> subvec(candidates.begin()+1, candidates.end());
                combina_iterate(cur_list, subvec, target, final_list);
                // cur_list.pop_back();
            }
        }
    }
};

int main(){
    Solution s;
    vector<int> candidates{2,3,5};
    int target = 8;
    vector<vector<int>> result = s.combinationSum(candidates, target);
    for (vector<vector<int>>::iterator t = result.begin(); t != result.end(); t++){
        vector<int> cur = *t;
        cout << "[" ;
        for (vector<int>::iterator p = cur.begin(); p!= cur.end(); p++){
            cout << *p << " ";
        }
        cout <<"]" << endl;

    }
    // std::cout << s.combinationSum(candidates, target) << endl;
    return 0;
}