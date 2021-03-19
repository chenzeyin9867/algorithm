#include <iostream>
#include<vector>
#include <algorithm>
#include <numeric>
using namespace std;
// author:rmokerone
#include <iostream>
#include <vector>

using namespace std;

class Solution {

private:
    vector<int> candidates;
    vector<vector<int>> res;
    vector<int> path;
public:
    void DFS(int start, int target) {
        if (target == 0) {
            res.push_back(path);
            return;
        }

        for (int i = start; i < candidates.size() && target - candidates[i] >= 0; i++) {
            if (i > start && candidates[i] == candidates[i - 1])
                continue;
            path.push_back(candidates[i]);
            // 元素不可重复利用，使用下一个即i+1
            DFS(i + 1, target - candidates[i]);
            path.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int> &candidates, int target) {
        sort(candidates.begin(), candidates.end());
        this->candidates = candidates;
        DFS(0, target);
        return res;
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