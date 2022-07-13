#include "head.h"
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        /* 
            Use double pointer, l for pos holds 0, 
            r for pos folds null-zeros          
         */
        int l = 0, r = 0;
        while(r < nums.size()){
            /* move the l to a zero place */
            while(l < nums.size() && nums[l] != 0){
                ++l;
            }
            /* now l points to a zero number,
               then move r to a null-zero number */
            r = l + 1;
            while(r < nums.size() && nums[r] == 0){
                ++r;
            }
            if(r >= nums.size()) break;
            /* swap the l and r */
            std::swap(nums[l], nums[r]);
            ++l;
        }
    }
};

int main(){
    Solution s;
    vector<int> input{0, 1, 0, 3, 12};
    s.moveZeroes(input);
    printVector(input);
    return 0;
}