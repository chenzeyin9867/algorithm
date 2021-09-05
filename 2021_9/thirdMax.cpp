#include "head.h"
class Solution {
public:
    int thirdMax(vector<int>& nums) {
        map<int , int> cnt;
        for(auto i : nums){
            cnt[i] ++;
        }
        int num = 3;
        for(auto i = cnt.rbegin(); i != cnt.rend(); i++){
            // cout << i->first << " " << i->second << endl;
            num --;
            if(num == 0) return i->first;
        }
        // cout << cnt.end()->first << " " << cnt.end()->second << endl;
        auto it = cnt.end();
        it--;
        // cout << it->first << " " << it->second << endl;
        return (it)->first;
        
    }
};

int main(){
    Solution s;
    vector<int> nums{5,2,2};
    s.thirdMax(nums);
    return 0;
}