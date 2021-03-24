#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int canjump[100000] = {0};
        if(nums.size()==1) return true;
        nums.insert(nums.begin(),0);
        canjump[nums.size()-1] = 1;
        for(int i = nums.size()-1; i >= 1; i--){
            int maxStep = nums[i];
            cout << maxStep << endl;
            for(int j = i+1; j <= nums.size() && j <= i + maxStep; j++){
                if(canjump[j] == 1){
                    canjump[i] = 1;
                    break;
                }
            }
        }
        if(canjump[1] == 1) return true;
        return false;
    }
};

int main(){
    Solution s;
    vector<int> list{2,0,0};
    cout << s.canJump(list) << endl;
}