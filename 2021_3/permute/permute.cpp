#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        if(nums.size() == 1){
            result.push_back(nums);
            return result;
        }
        result = subpermute(nums);
        return result;
    }
    
    vector<vector<int>> subpermute(vector<int> & nums){
        vector<vector<int>> tmp_r;
        if(nums.size()==2){
            tmp_r.push_back(vector<int>{nums[0], nums[1]});
            tmp_r.push_back(vector<int>{nums[1], nums[0]});
        }
        else{
            
            for(int i = 0; i < nums.size(); i++){
                vector<int> tmpNum = nums;
                int cur = nums[i];
                // cout << cur << endl;
                vector<vector<int>> tmp_result;
                tmpNum.erase(tmpNum.begin()+i);
                // for (int i = 0; i< tmpNum.size(); i++){
                //     cout << tmpNum[i] << " ";
                // }
                // cout << endl;
                tmp_result = subpermute(tmpNum);
                for(int j = 0; j< tmp_result.size() ; j++){
                    vector<int> t = tmp_result[j];
                    t.insert(t.begin(), cur);
                    tmp_r.push_back(t);
                }
                
                
            }
        }
        return tmp_r;
    }

private:
    vector<vector<int>> result;
};

int main(){
    Solution s;
    vector<int>num{2};
    vector<vector<int>> result = s.permute(num);
    // cout << "size " << result.size() << endl;
    for (int i = 0 ; i < result.size(); i++){
        vector<int> r = result[i];
        for(int j = 0; j < r.size(); j++){
            cout << r[j] << " ";
        }
        cout << endl;
    }
    
}