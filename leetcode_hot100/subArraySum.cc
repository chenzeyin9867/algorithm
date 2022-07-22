#include "head.h"
/* One eye, I just know using the sliding window, hahahaha */
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int l = 0, r = 0;
        int cur = 0;
        // int cnt = 0;
        int sum = 0;
        unordered_map<int, int> cnt;
        // if(nums.front() != 0)
        cnt[0] = 1;
        if(nums.front() == k) ++sum;
        cnt[nums.front()]++;
        /* Construct a accumulating array. */
        for(int i = 1; i < nums.size(); ++i){
            nums[i] = nums[i] + nums[i-1];

            // ++cnt[nums[i]];
            sum += cnt[nums[i]-k];
            ++cnt[nums[i]];
        }
        // int sum = 0;
        return sum;
    }
};

int main(){
    Solution s;
    vector<int> vec{0, 0};
    cout << "num of combination " << s.subarraySum(vec, 0) << endl;
    return 0;
}