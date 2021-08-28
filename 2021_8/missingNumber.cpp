#include "head.h"
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int sum = 0;
        int n = nums.size();
        for(int i = 0; i < n; i++){
            sum += nums[i];
        }
        return (1+n)*n/2 - sum;
    }
};

int main(){
    Solution s;
    vector<int> nums{9,6,4,2,3,5,7,0,1};
    cout << s.missingNumber(nums) << endl;
    return 0;
}