#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    vector<vector<int>> result;
    vector<int > med;
    vector<vector<int>> subsets(vector<int>& nums) {
        if(nums.size() == 1) {
            result.push_back(med);
            med.push_back(nums[0]);
            result.push_back(med);
            med.pop_back();
        }else{
            vector<int> tmp(nums.begin()+1, nums.end());
            subsets(tmp);
            // med.pop_back();
            med.push_back(nums[0]);
            subsets(tmp);
            med.pop_back();
        }
        return result;
    }
    // return result;
};

int main(){
    Solution s;
    vector<int> nums{0,1,2,3,4,5};
    vector<vector<int> > result = s.subsets(nums);
    for(int i = 0 ; i < result.size(); i++){
        cout << "[";
        for(int j =0; j < result[i].size(); j++){
            cout << result[i][j] << " " ;
        }
        cout << "]\n";
    }    
    return 0;
}