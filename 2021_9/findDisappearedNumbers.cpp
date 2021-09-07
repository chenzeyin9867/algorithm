#include "head.h"
class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        vector<int> result;
        int cnt[1000001];
        // for(int i =1; i < 100;i ++) cout << cnt[i] << endl;
        for(auto i: nums){
            cnt[i]++;
        }
        for(int i = 1; i <= nums.size(); i++){
            cout << cnt[i] << endl;
            if(!cnt[i]){
                result.emplace_back(i);
            }
        }
        return result;
    }
};

int main(){
    Solution s;
    vector<int> nums{1,1};
    vector<int>r = s.findDisappearedNumbers(nums);
    printVector(r);
    return 0;
}