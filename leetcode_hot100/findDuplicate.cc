#include "head.h"
/* We use cnt[i] to count the number less or equal then i, which means
   if k duplicates, for any j >= k, cnt[j] > j, so we just to find the
   first k satisfy cnt[k] > k. */
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int l = 0, r = nums.size() - 1;
        while(l <= r){
            int mid = (r - l)/ 2 + l;
            /* Check whether cnt[mid] > mid */
            int cnt = 0;
            for(int i = 0; i < nums.size(); ++i){
                if(nums[i] <= mid){
                    ++cnt;
                }
            }
            if(cnt <= mid){
                l = mid + 1;
            }else{
                r = mid - 1;
            }
        }
        return r + 1;
    }
};

int main(){
    Solution s;
    vector<int> input {1, 2,2, 4,5,6};
    cout << "Duplicate number: " << s.findDuplicate(input) << std::endl;
    return 0;
}