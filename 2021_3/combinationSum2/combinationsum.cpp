#include <iostream>
#include<vector>
#include <algorithm>
#include <numeric>
using namespace std;
class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end()); // sort the vector first for the  pruning
        vector <vector <int> > result;
        vector<int>cur_list;
        dfs(candidates, cur_list, result, target);
        return result;
    }

    void dfs(vector<int>& candidates, vector<int>&cur_list, vector<vector<int>> &final_result, int target){
        int sum = accumulate(cur_list.begin(), cur_list.end(), 0);
        if(sum == target){
            final_result.push_back(cur_list);
        }else{
            if(sum > target){
                return;
            }
            if(candidates.size() == 0){
                return;
            }
            vector<int> tmp(candidates.begin() + 1, candidates.end());
            cur_list.push_back(candidates[0]);
            dfs(tmp, cur_list,final_result, target);
            cur_list.pop_back();
            dfs(tmp, cur_list, final_result, target);
        }

        
    }
};
int main(){
    Solution s;

    vector<int> candidates = {2,5,2,1,2};
    int  target = 5;
    vector<vector<int>> r = s.combinationSum2(candidates, target);
    for (int i =0 ;i< r.size() ;i++){
        vector<int> cur = r[i];
        for(int j =0 ;j< cur.size(); j++){
            cout << cur[j] << " ";
        }
        cout << endl;
    }
}