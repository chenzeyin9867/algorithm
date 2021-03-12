#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int len = nums.size();
        if (len == 1){
            return nums[0];
        }else{
            int max = nums[0];
            int f[100000];
            f[0] = nums[0];
            for (int i = 1 ; i < len; i++){
                f[i] = nums[i] > f[i-1] + nums[i] ? nums[i] : f[i-1] + nums[i];
                if (f[i] > max){
                    max = f[i];
                }
            }
            return max;
        }
    }
};

int main(){
    vector<int>nums = {-1,-2};
    Solution s;
    cout << s.maxSubArray(nums) << endl;

    return 0;
}