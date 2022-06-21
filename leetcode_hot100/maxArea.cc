#include "head.h"
class Solution {
public:
    int maxArea(vector<int>& height) {
        if(height.size() == 0) return 0;
        int max_size = 0;
        int l = 0, r = height.size() - 1;
        while(l < r){
            max_size = std::max((r - l) * std::min(height[l], height[r]), max_size); /* Compute the area */
            /* move the smaller edge first */
            if(height[l] <= height[r]){
                int old_l = l;
                /* move the l bound until height[new_l] > height[l] */
                while(l < r && height[l] <= height[old_l]){
                    ++l;
                }  
            }else{
                /* move the r bound */
                int old_r = r;
                while(l < r && height[r] <= height[old_r]){
                    --r;
                }
            }
        }
        return max_size;
    }
};

int main(){
    Solution s;
    vector<int> height{1,8,6,2,5,4,8,3,7};
    std::cout << s.maxArea(height) << std::endl;
    return 0;

}