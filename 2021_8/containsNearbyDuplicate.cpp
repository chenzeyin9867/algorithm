#include "head.h"
class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        queue<int> q;
        set<int> s ;
        for(int i = 0; i < nums.size(); i++){
            if(s.find(nums[i])!=s.end()) return true;
            q.emplace(nums[i]);
            s.emplace(nums[i]);
            if(q.size()>= k+1){
                int t = q.front();
                q.pop();
                s.erase(t);
            }
        }
        return false;
    }

};

int main(){
    Solution s;
    vector<int> a{1,2,3,1};
    cout << s.containsNearbyDuplicate(a, 3) << endl;
    return 0;
}